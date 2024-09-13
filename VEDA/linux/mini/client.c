#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>

#define CHUNK_SIZE 1024
#define TCP_PORT 5200
#define MAX_ID_LEN 20
#define MAX_MSG_LEN 256
#define BBUFSIZ 1024

int ssock;
char user_id[MAX_ID_LEN];
char mesg[BBUFSIZ];

// 파일 전송 함수
void send_file(int sockfd, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("File open error");
        return;
    }

    // 파일 크기 계산
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // 서버에 파일 전송 요청
    char send_msg[BUFSIZ];
    snprintf(send_msg, sizeof(send_msg), "SEND_FILE:%s", filename);
    write(sockfd, send_msg, strlen(send_msg) + 1);

    // 파일 크기 전송
    write(sockfd, &file_size, sizeof(file_size));

    // 파일 데이터 전송
    char file_buffer[CHUNK_SIZE];
    int bytes_read;
    while ((bytes_read = fread(file_buffer, sizeof(char), CHUNK_SIZE, fp)) > 0) {
        write(sockfd, file_buffer, bytes_read);
    }

    fclose(fp);
    printf("File %s send ok\n", filename);
}
// 파일 수신 함수
void receive_file(int sockfd) {
    char filename[BUFSIZ];
    int file_size;

    // 파일 이름과 크기 수신
    read(sockfd, filename, sizeof(filename));
    read(sockfd, &file_size, sizeof(file_size));

    printf("File received request: %s (Size: %d bytes)\n", filename, file_size);

    // 파일 저장
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("File open error");
        return;
    }

    int bytes_received = 0;
    char file_buffer[CHUNK_SIZE];
    while (bytes_received < file_size) {
        int chunk = read(sockfd, file_buffer, CHUNK_SIZE);
        fwrite(file_buffer, sizeof(char), chunk, fp);
        bytes_received += chunk;
    }

    fclose(fp);
    printf("File %s received ok\n", filename);
}

void cleanup() {
    close(ssock);
    exit(0);
}

void handle_signal(int sig) {
    cleanup();
}

void display_menu() {
    system("clear");
    printf("\n===== MENU =====\n");
    printf("1. Login\n");
    printf("2. Chatting Strat\n");
    printf("3. Logout\n");
    printf("4. Search MSG\n");
    printf("5. File Transfer\n");
    printf("6. EXIT\n");
    printf("> ");
}

int main(int argc, char **argv)
{   
    if (argc < 2) {
        printf("./client <ip> \n");
        return 1; // 오류 코드 반환
    }

    // TCP 소켓 생성
    struct sockaddr_in servaddr;
    pid_t pid; 
    //int n;

    if ((ssock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("can not create sock");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    /* 문자열을 네트워크 주소로 변경 */
    inet_pton(AF_INET, argv[1], &(servaddr.sin_addr.s_addr));
    servaddr.sin_port = htons(TCP_PORT);

    if (connect(ssock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("can not connect server");
        return 1;
    }

    printf("\033[32m[Connected]\033[0m\n");
    printf("\033[32m[Press Enter]\033[0m\n");
    getchar();
    signal(SIGINT, handle_signal);

    while (1) {
        system("clear");
        display_menu();
        int op;
        scanf("%d", &op);
        getchar(); // 버퍼 비우기

        switch (op) {
            case 1: // 로그인
                if(strlen(user_id) != 0) {
                    printf("Already login. ID : %s\n", user_id);
                    printf("\033[32m[Press Enter]\033[0m\n");
                    getchar();
                    continue;
                }
                printf("Input User ID: ");
                fgets(user_id, MAX_ID_LEN, stdin);
                user_id[strcspn(user_id, "\n")] = 0; // 개행 문자 제거
                sprintf(mesg, "LOGIN:%s", user_id);
                send(ssock, mesg, strlen(mesg), 0);

                // 서버로부터 응답 받기
                memset(mesg, 0, BBUFSIZ);
                if (recv(ssock, mesg, BBUFSIZ, 0) > 0) {
                    printf("Server On: %s\n", mesg);
                }
                getchar();
                break;
            case 2: // 채팅하기
                if (strlen(user_id) == 0) {
                    printf("First you must login.\n");
                    getchar();
                    continue;
                }
                pid = fork();
                if (pid < 0) {
                    perror("Error");
                } else if (pid == 0) {
                    // 자식 프로세스: 메시지 전송
                    printf("Input message ('q' to quit) > ");
                    while(1) {
                        char temp[MAX_MSG_LEN];
                        fgets(temp, MAX_MSG_LEN, stdin);
                        temp[strcspn(temp, "\n")] = 0; // 개행 문자 제거
                        if (strcmp(temp, "q") == 0) {
                            send(ssock, "q", 1, 0);
                            exit(0);
                        }
                        sprintf(mesg, "%s : %s", user_id, temp);
                        send(ssock, mesg, strlen(mesg), 0);
                    }
                } else {
                    // 부모 프로세스: 메시지 수신
                    while(1) {
                        memset(mesg, 0, BBUFSIZ);
                        if(recv(ssock, mesg, BBUFSIZ, 0) <= 0) {
                            perror("recv()");
                            kill(pid, SIGTERM);
                            break;
                        } else if(strncmp(mesg, "Client", 5) == 0) {
                            printf("\n");
                            printf("\033[32m[Press Enter]\033[0m\n");
                            break;
                        } else {
                            printf("%s\n", mesg);
                            fflush(stdout); 
                        }
                    }
                    waitpid(pid, NULL, 0);
                }
                getchar();
                continue;
            case 3: // 로그아웃
                if (strlen(user_id) == 0) {
                    printf("You have to login.\n");
                    getchar();
                    continue;
                }
                sprintf(mesg, "LOGOUT:%s", user_id);
                send(ssock, mesg, strlen(mesg), 0);
                memset(user_id, 0, MAX_ID_LEN);
                printf("LOGOUT.\n");

                // 서버로부터 응답 받기
                memset(mesg, 0, BBUFSIZ);
                if (recv(ssock, mesg, BBUFSIZ, 0) > 0) {
                    printf("Respond:%s\n", mesg);
                }
                getchar();
                break;
            case 4: // 메시지 검색
                printf("Input the user ID you want to search for: ");
                char search_id[MAX_ID_LEN];
                fgets(search_id, MAX_ID_LEN, stdin);
                search_id[strcspn(search_id, "\n")] = 0; // 개행 문자 제거

                // 서버에 검색 요청 전송
                sprintf(mesg, "SEARCH:%s", search_id);
                send(ssock, mesg, strlen(mesg), 0);

                // 서버로부터 검색 결과 수신
                memset(mesg, 0, BBUFSIZ);
                if (recv(ssock, mesg, BBUFSIZ, 0) > 0) {
                    printf("RESULT:\n%s\n", mesg);
                }
                
                getchar();
                break;

            case 5: // 파일 전송
                char filename[BUFSIZ];
                printf("File name : ");
                fgets(filename, BUFSIZ, stdin);
                filename[strcspn(filename, "\n")] = 0;  // 개행 문자 제거
                send_file(ssock, filename);
                break;

            case 6: // 종료
                sprintf(mesg, "quit");
                send(ssock, mesg, strlen(mesg), 0);
                cleanup();
                break;
            default:
                printf("RETRY.\n");
                getchar();
                continue;
        }
    }

    return 0;
}