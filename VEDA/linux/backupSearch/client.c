#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>

#define TCP_PORT 5200
#define MAX_ID_LEN 20
#define MAX_MSG_LEN 256
#define BBUFSIZ 1024

int ssock;
char user_id[MAX_ID_LEN];
char mesg[BBUFSIZ];

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
    struct sockaddr_in servaddr;
    pid_t pid; 
    int n;

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
                    printf("로그인 상태입니다. ID : %s\n", user_id);
                    printf("\033[32m[Press Enter]\033[0m\n");
                    getchar();
                    continue;
                }
                printf("사용자 ID 입력: ");
                fgets(user_id, MAX_ID_LEN, stdin);
                user_id[strcspn(user_id, "\n")] = 0; // 개행 문자 제거
                sprintf(mesg, "LOGIN:%s", user_id);
                send(ssock, mesg, strlen(mesg), 0);

                // 서버로부터 응답 받기
                memset(mesg, 0, BBUFSIZ);
                if (recv(ssock, mesg, BBUFSIZ, 0) > 0) {
                    printf("서버 응답: %s\n", mesg);
                }
                getchar();
                break;
            case 2: // 채팅하기
                if (strlen(user_id) == 0) {
                    printf("먼저 로그인해주세요.\n");
                    getchar();
                    continue;
                }
                pid = fork();
                if (pid < 0) {
                    perror("Error");
                } else if (pid == 0) {
                    // 자식 프로세스: 메시지 전송
                    printf("메시지 입력 (q로 종료)\n");
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
                            printf("채팅 종료\n");
                            printf("엔터를 눌러주세요.\n");
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
                    printf("로그인 상태가 아닙니다.\n");
                    getchar();
                    continue;
                }
                sprintf(mesg, "LOGOUT:%s", user_id);
                send(ssock, mesg, strlen(mesg), 0);
                memset(user_id, 0, MAX_ID_LEN);
                printf("로그아웃되었습니다.\n");

                // 서버로부터 응답 받기
                memset(mesg, 0, BBUFSIZ);
                if (recv(ssock, mesg, BBUFSIZ, 0) > 0) {
                    printf("서버 응답: %s\n", mesg);
                }
                getchar();
                break;
            case 4: // 메시지 검색
                printf("검색할 사용자 ID 입력: ");
                char search_id[MAX_ID_LEN];
                fgets(search_id, MAX_ID_LEN, stdin);
                search_id[strcspn(search_id, "\n")] = 0; // 개행 문자 제거

                // 서버에 검색 요청 전송
                sprintf(mesg, "SEARCH:%s", search_id);
                send(ssock, mesg, strlen(mesg), 0);

                // 서버로부터 검색 결과 수신
                memset(mesg, 0, BBUFSIZ);
                if (recv(ssock, mesg, BBUFSIZ, 0) > 0) {
                    printf("검색 결과:\n%s\n", mesg);
                }

                getchar();
                break;
            case 5: // 파일 전송
                break;
            case 6: // 종료
                sprintf(mesg, "quit");
                send(ssock, mesg, strlen(mesg), 0);
                cleanup();
                break;
            default:
                printf("잘못된 선택입니다. 다시 선택해주세요.\n");
                getchar();
                continue;
        }
    }

    return 0;
}