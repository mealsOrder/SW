#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>

#define CHUNK_SIZE 1024
#define BBUFSIZ 1024
#define MAX_ID_LEN 20
#define MAX_MSG_LEN 256
#define TCP_PORT 5200
#define MAX_CLIENTS 5

// 클라이언트 소켓 정보를 저장하는 구조체
typedef struct client_info {
    char ip[BUFSIZ];
    char name[BUFSIZ];
    int id;
    int infofd;
} info;

static int client_cnt = 0;   // 현재 연결된 클라이언트 수
int pipefd[2];  // 프로세스 간 통신을 위한 파이프
info* fo[MAX_CLIENTS];    // 클라이언트 소켓 정보 배열

// 자식 프로세스 종료 처리 함수
void sigchld_handler(int signum) {
    int cur;
    pid_t pid;
    while ((pid = waitpid(-1, &cur, WNOHANG)) > 0) {
        for (int i = 0; i < client_cnt; i++) {
            if (fo[i]->id == pid) {
                close(fo[i]->infofd);
                free(fo[i]);
                for (int j = i; j < client_cnt - 1; j++) {
                    fo[j] = fo[j+1];
                }
                client_cnt--;
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
        for (int i = 0; i < client_cnt; i++) {
            if (fo[i]->id == sender_pid) {
                ptr = strtok(message, ":");
                strcpy(fo[i]->name, ptr);
                write(fo[i]->infofd, message, strlen(message));
                break;
            }
        }
    } else {
        for (int i = 0; i < client_cnt; i++) {
            if (fo[i]->id != sender_pid) {
                write(fo[i]->infofd, message, strlen(message));
            }
        }
    }
}

// SIGUSR1 시그널 핸들러 (브로드캐스트 메시지 처리)
void sigusr1_handler(int signum) {
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
        if ((n = read(fo[client_index]->infofd, mesg, BUFSIZ)) <= 0) {
            break;
        }
        printf("%s\n", mesg);

        char broadcast_msg[BUFSIZ + 50];
        if(strncmp(mesg, "LOGIN:", 6) == 0) {
            snprintf(broadcast_msg, sizeof(broadcast_msg), "Login success");
            
            // 클라이언트 이름 저장 (로그인 시 ID를 이름으로 사용)
            strcpy(fo[client_index]->name, mesg + 6);  // "LOGIN:" 이후의 ID 저장

        } 
        // 로그아웃
        else if(strncmp(mesg, "LOGOUT:", 7) == 0) {
            snprintf(broadcast_msg, sizeof(broadcast_msg), "Logout success");
        }  
        // 채팅 종료
        else if (strcmp(mesg, "q") == 0) {
            snprintf(broadcast_msg, sizeof(broadcast_msg), "Client %s is disconnecting.", fo[client_index]->ip);
        } 
        // 채팅종료
        else if (strcmp(mesg, "quit") == 0) {
            printf("Client %s is disconnecting.\n", fo[client_index]->ip);
            break;
        } 
        // 파일 검색
        else if (strncmp(mesg, "SEARCH:", 7) == 0) {
            char search_id[MAX_ID_LEN];
            strcpy(search_id, mesg + 7);

            // 사용자 메시지 파일 열기
            fp = fopen(search_id, "r");
            if (fp == NULL) {
                // TODO : 이거 뒤에 왜 disconnectting 이 한번씩 나올까 ?
                //sprintf(mesg, "해당 사용자의 메시지가 없습니다.");
                printf("No message!\n");
            } else {
                char line[MAX_MSG_LEN];
                memset(mesg, 0, BBUFSIZ);
                while (fgets(line, sizeof(line), fp) != NULL) {
                    strcat(mesg, line);
                }
                fclose(fp);
            }
            // 검색 결과를 클라이언트에게 전송
            write(fo[client_index]->infofd, mesg, strlen(mesg));
        }
        // 파일 전송
        else if (strncmp(mesg, "SEND_FILE:", 10) == 0) {
            char filename[MAX_ID_LEN];
            strcpy(filename, mesg + 10);  // 파일 이름 가져오기

            // 파일 크기 정보 받기
            int file_size;
            read(fo[client_index]->infofd, &file_size, sizeof(file_size));
            printf("File: %s Size: %d bytes\n", filename, file_size);

            // 파일 저장을 위해 열기
            fp = fopen(filename, "wb");
            if (fp == NULL) {
                perror("File open error");
                continue;
            }

            // 파일 데이터를 수신하여 저장
            int bytes_received = 0;
            char file_buffer[CHUNK_SIZE];
            while (bytes_received < file_size) {
                int chunk = read(fo[client_index]->infofd, file_buffer, CHUNK_SIZE);
                fwrite(file_buffer, sizeof(char), chunk, fp);
                bytes_received += chunk;
            }

            fclose(fp);
            printf("File %s received ok\n", filename);

            // 파일을 다른 클라이언트들에게 전송
            for (int i = 0; i < client_cnt; i++) {
                if (i != client_index) {  // 전송한 클라이언트는 제외
                    // 파일 이름과 크기 전송
                    write(fo[i]->infofd, "RECEIVE_FILE:", 13);
                    write(fo[i]->infofd, filename, strlen(filename) + 1);
                    write(fo[i]->infofd, &file_size, sizeof(file_size));

                    // 파일 데이터를 다시 전송
                    fp = fopen(filename, "rb");
                    if (fp != NULL) {
                        int bytes_sent = 0;
                        while (bytes_sent < file_size) {
                            int chunk = fread(file_buffer, sizeof(char), CHUNK_SIZE, fp);
                            write(fo[i]->infofd, file_buffer, chunk);
                            bytes_sent += chunk;
                        }
                        fclose(fp);
                        printf("File %s send to client ok\n", filename);
                    }
                }
            }
        }
        else {
            // 현재 시간 가져오기
            time(&rawtime);
            timeinfo = localtime(&rawtime);

            // 메시지를 해당 유저의 파일에 저장
            fp = fopen(fo[client_index]->name, "a");
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
    snprintf(disconnect_msg, sizeof(disconnect_msg), "Client %s has disconnected.\n", fo[client_index]->ip);
    write(pipefd[1], &pid, sizeof(int));
    write(pipefd[1], disconnect_msg, strlen(disconnect_msg) + 1);
    kill(getppid(), SIGUSR1);

    close(fo[client_index]->infofd);
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

        if (client_cnt >= MAX_CLIENTS) {
            printf("Already Max clients\n");
            close(csock);
            continue;
        }

        fo[client_cnt] = (info*)malloc(sizeof(info));
        inet_ntop(AF_INET, &cliaddr.sin_addr, fo[client_cnt]->ip, BUFSIZ);
        fo[client_cnt]->infofd = csock;

        printf("Client is connected: %s\n", fo[client_cnt]->ip);

        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            close(ssock);
            fo[client_cnt]->id = getpid();
            handle_client(client_cnt);
        } else {
            fo[client_cnt]->id = pid;
            client_cnt++;
        }
    }

    close(ssock);
    return 0;
}