#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <time.h>

#define BBUFSIZ 1024
#define MAX_ID_LEN 20
#define MAX_MSG_LEN 256
#define TCP_PORT 5200
#define MAX_CLIENTS 5

// 클라이언트 소켓 정보를 저장하는 구조체
typedef struct client_sock {
    char ip[BUFSIZ];
    char name[BUFSIZ];
    int id;
    int csfd;
} c_sock;

// 전역 변수 선언
static int g_noc = 0;   // 현재 연결된 클라이언트 수
int pipefd[2];  // 프로세스 간 통신을 위한 파이프
c_sock* cs[MAX_CLIENTS];    // 클라이언트 소켓 정보 배열

// 자식 프로세스 종료 처리 함수
void sigchld_handler(int signo) {
    int status;
    pid_t pid;
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        for (int i = 0; i < g_noc; i++) {
            if (cs[i]->id == pid) {
                close(cs[i]->csfd);
                free(cs[i]);
                for (int j = i; j < g_noc - 1; j++) {
                    cs[j] = cs[j+1];
                }
                g_noc--;
                break;
            }
        }
    }
}

// 모든 클라이언트에게 메시지 브로드캐스트 함수
void broadcast_message(char *message, int sender_pid) {
    // ... (sender_pid를 제외한 모든 클라이언트에게 메시지 전송)
    char *ptr; 
    if(strcmp(message, "Login success") == 0 || strcmp(message, "Logout success") == 0 || strncmp(message, "Client", 5) == 0) {
        for (int i = 0; i < g_noc; i++) {
            if (cs[i]->id == sender_pid) {
                ptr = strtok(message, ":");
                strcpy(cs[i]->name, ptr);
                write(cs[i]->csfd, message, strlen(message));
                break;
            }
        }
    } else {
        for (int i = 0; i < g_noc; i++) {
            if (cs[i]->id != sender_pid) {
                write(cs[i]->csfd, message, strlen(message));
            }
        }
    }
}

// SIGUSR1 시그널 핸들러 (브로드캐스트 메시지 처리)
void sigusr1_handler(int signo) {
    // ... (파이프에서 메시지를 읽어 브로드캐스트)
    char broadcast_msg[BUFSIZ + 50];
    int sender_pid;
    
    read(pipefd[0], &sender_pid, sizeof(int));
    read(pipefd[0], broadcast_msg, sizeof(broadcast_msg));
    
    broadcast_message(broadcast_msg, sender_pid);
}

// 클라이언트 처리 함수
void handle_client(int client_index) {
    char mesg[BUFSIZ];
    int n;
    pid_t pid = getpid();

    // 파일 포인터 선언
    FILE *fp;

    // 시간 저장을 위한 변수 선언
    time_t rawtime;
    struct tm *timeinfo;

    while (1) {
        memset(mesg, 0, BUFSIZ);
        if ((n = read(cs[client_index]->csfd, mesg, BUFSIZ)) <= 0) {
            break;
        }
        printf("%s\n", mesg);

        char broadcast_msg[BUFSIZ + 50];
        if(strncmp(mesg, "LOGIN:", 6) == 0) {
            snprintf(broadcast_msg, sizeof(broadcast_msg), "Login success");
            
            // 클라이언트 이름 저장 (로그인 시 ID를 이름으로 사용)
            strcpy(cs[client_index]->name, mesg + 6);  // "LOGIN:" 이후의 ID 저장

        } else if(strncmp(mesg, "LOGOUT:", 7) == 0) {
            snprintf(broadcast_msg, sizeof(broadcast_msg), "Logout success");
        }  else if (strcmp(mesg, "q") == 0) {
            snprintf(broadcast_msg, sizeof(broadcast_msg), "Client %s is disconnecting.", cs[client_index]->ip);
        } else if (strcmp(mesg, "quit") == 0) {
            printf("Client %s is disconnecting.\n", cs[client_index]->ip);
            break;
        } else if (strncmp(mesg, "SEARCH:", 7) == 0) {
            char search_id[MAX_ID_LEN];
            strcpy(search_id, mesg + 7);

            // 사용자 메시지 파일 열기
            fp = fopen(search_id, "r");
            if (fp == NULL) {
                sprintf(mesg, "해당 사용자의 메시지가 없습니다.");
            } else {
                char line[MAX_MSG_LEN];
                memset(mesg, 0, BBUFSIZ);
                while (fgets(line, sizeof(line), fp) != NULL) {
                    strcat(mesg, line);
                }
                fclose(fp);
            }
            // 검색 결과를 클라이언트에게 전송
            write(cs[client_index]->csfd, mesg, strlen(mesg));
        }
         else {
            // 현재 시간 가져오기
            time(&rawtime);
            timeinfo = localtime(&rawtime);

            // 메시지를 해당 유저의 파일에 저장
            fp = fopen(cs[client_index]->name, "a");
            if (fp != NULL) {
                fprintf(fp, "[%02d-%02d-%04d %02d:%02d:%02d] %s\n", 
                        timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, 
                        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, mesg);  // 시간과 메시지를 파일에 저장
                fclose(fp);
            }
            snprintf(broadcast_msg, sizeof(broadcast_msg), "%s", mesg);
        }
        
        write(pipefd[1], &pid, sizeof(int));
        write(pipefd[1], broadcast_msg, strlen(broadcast_msg) + 1);
        kill(getppid(), SIGUSR1);
    }

    // 클라이언트 종료 메시지 전송
    char disconnect_msg[BUFSIZ + 50];
    snprintf(disconnect_msg, sizeof(disconnect_msg), "Client %s has disconnected.\n", cs[client_index]->ip);
    write(pipefd[1], &pid, sizeof(int));
    write(pipefd[1], disconnect_msg, strlen(disconnect_msg) + 1);
    kill(getppid(), SIGUSR1);

    close(cs[client_index]->csfd);
    exit(0);
}

int main(int argc, char **argv) {
    int ssock, csock;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clen;
    pid_t pid;

    if (pipe(pipefd) < 0) {
        perror("pipe");
        exit(1);
    }

    signal(SIGCHLD, sigchld_handler);
    signal(SIGUSR1, sigusr1_handler);

    if ((ssock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(TCP_PORT);

    if (bind(ssock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(ssock, 8) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        clen = sizeof(cliaddr);
        if ((csock = accept(ssock, (struct sockaddr *)&cliaddr, &clen)) < 0) {
            perror("accept");
            continue;
        }

        if (g_noc >= MAX_CLIENTS) {
            printf("최대 클라이언트 수에 도달했습니다. 연결을 거부합니다.\n");
            close(csock);
            continue;
        }

        cs[g_noc] = (c_sock*)malloc(sizeof(c_sock));
        inet_ntop(AF_INET, &cliaddr.sin_addr, cs[g_noc]->ip, BUFSIZ);
        cs[g_noc]->csfd = csock;

        printf("Client is connected: %s\n", cs[g_noc]->ip);

        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            close(ssock);
            cs[g_noc]->id = getpid();
            handle_client(g_noc);
        } else {
            cs[g_noc]->id = pid;
            g_noc++;
        }
    }

    close(ssock);
    return 0;
}