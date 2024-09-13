#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <signal.h>
#include <fcntl.h>
#include <ncurses.h>

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
        perror("파일 열기 실패");
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
    printw("파일 %s 전송 완료\n", filename);
    refresh();
}
// 파일 수신 함수
void receive_file(int sockfd) {
    char filename[BUFSIZ];
    int file_size;

    // 파일 이름과 크기 수신
    read(sockfd, filename, sizeof(filename));
    read(sockfd, &file_size, sizeof(file_size));

    printf("파일 수신 요청: %s (크기: %d bytes)\n", filename, file_size);

    // 파일 저장
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("파일 열기 실패");
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
    printw("파일 %s 수신 완료\n", filename);
    refresh();
}

void cleanup() {
    close(ssock);
    endwin(); // ncurses 종료
    exit(0);
}

void handle_signal(int sig) {
    cleanup();
}

// 화면을 그리는 함수
void draw_chat_ui(WINDOW *chat_win, WINDOW *input_win) {
    // int chat_win_height, chat_win_width;
    // int input_win_height, input_win_width;

    // getmaxyx(chat_win, chat_win_height, chat_win_width);
    // getmaxyx(input_win, input_win_height, input_win_width);

    // 채팅 표시 박스 그리기
    wclear(chat_win);  // 창을 지운 후 다시 그리기
    box(chat_win, 0, 0);
    mvwprintw(chat_win, 0, 2, " Chat ");
    wrefresh(chat_win);

    // 입력 박스 그리기
    wclear(input_win);  // 창을 지운 후 다시 그리기
    box(input_win, 0, 0);
    mvwprintw(input_win, 0, 2, " Input ");
    wrefresh(input_win);
}

// 클라이언트로 메시지 전송
void send_message(WINDOW *input_win) {
    char temp[MAX_MSG_LEN];
    mvwgetnstr(input_win, 1, 1, temp, MAX_MSG_LEN); // 입력받기
    temp[strcspn(temp, "\n")] = 0; // 개행 문자 제거
    if (strcmp(temp, "q") == 0) {
        send(ssock, "q", 1, 0);
        exit(0);
    }
    sprintf(mesg, "%s : %s", user_id, temp);
    send(ssock, mesg, strlen(mesg), 0);
    wclear(input_win);  // 입력 후 창 지우기
    box(input_win, 0, 0);  // 다시 박스 그리기
    mvwprintw(input_win, 0, 2, " Input ");
    wrefresh(input_win);
}

/* ui 관랸 */

// 메뉴
void display_menu(int highlight) {
    clear();
    printw("\n===== MENU =====\n");
    const char *menu_items[] = {
        "1. Login",
        "2. Chatting Start",
        "3. Logout",
        "4. Search MSG",
        "5. File Transfer",
        "6. EXIT",
        NULL // 마지막 요소는 NULL로 설정
    };

    for (int i = 0; menu_items[i] != NULL; i++) {
        if (i == highlight) {
            attron(A_REVERSE); // 강조 효과
            printw("%s\n", menu_items[i]);
            attroff(A_REVERSE); // 강조 효과 해제
        } else {
            printw("%s\n", menu_items[i]);
        }
    }
    refresh();
}
void start_chat() {
    int pid;
    int max_y, max_x;
    
    // ncurses 초기화
    initscr();
    cbreak();
    noecho();
    curs_set(0); // 커서 안 보이게 설정
    getmaxyx(stdscr, max_y, max_x);

    int chat_win_height = max_y - 5; // 채팅 내용 창 높이 (상단 박스)
    int input_win_height = 3;        // 입력 창 높이 (하단 박스)
    
    // 상단 채팅 내용 창
    WINDOW *chat_win = newwin(chat_win_height, max_x, 0, 0);
    box(chat_win, 0, 0);
    scrollok(chat_win, TRUE);  // 스크롤 허용
    wrefresh(chat_win);

    // 하단 입력 창
    WINDOW *input_win = newwin(input_win_height, max_x, chat_win_height, 0);
    box(input_win, 0, 0);
    mvwprintw(input_win, 1, 1, "Input Message (q:quit) > ");
    wrefresh(input_win);

    int line = 1;  // 채팅창의 현재 라인 번호

    pid = fork();
    if (pid < 0) {
        perror("Error");
    } else if (pid == 0) {
        // 자식 프로세스: 메시지 전송
        char temp[MAX_MSG_LEN];
        while (1) {
            // 입력 창에 메시지 입력 받기
            echo();  // 입력한 문자를 보이게 함
            curs_set(1);  // 커서 보이게 설정
            wmove(input_win, 1, 25);  // 입력 위치로 이동
            wgetnstr(input_win, temp, MAX_MSG_LEN);  // 입력 받기
            noecho();  // 다시 입력한 문자를 안 보이게 설정
            curs_set(0);  // 커서 숨김

            if (strcmp(temp, "q") == 0) {
                send(ssock, "q", 1, 0);
                exit(0);
            }

            sprintf(mesg, "%s : %s", user_id, temp);
            send(ssock, mesg, strlen(mesg), 0);

            // 입력 후 입력창 초기화
            wclear(input_win);
            box(input_win, 0, 0);
            mvwprintw(input_win, 1, 1, "message(q:quit) > ");
            wrefresh(input_win);
        }
    } else {
        // 부모 프로세스: 메시지 수신
        while (1) {
            memset(mesg, 0, BBUFSIZ);
            if (recv(ssock, mesg, BBUFSIZ, 0) <= 0) {
                perror("recv()");
                kill(pid, SIGTERM);
                break;
            } else if (strncmp(mesg, "Client", 5) == 0) {
                mvwprintw(chat_win, line++, 1, "채팅 종료");
                mvwprintw(chat_win, line++, 1, "엔터를 눌러주세요.");
                wrefresh(chat_win);
                break;
            } else {
                if (line >= chat_win_height - 2) {
                    // 상단 채팅창이 가득 차면 초기화
                    wclear(chat_win);
                    box(chat_win, 0, 0);
                    line = 1; // 처음 라인으로 초기화
                }

                // 수신한 메시지를 상단 채팅 창에 출력
                mvwprintw(chat_win, line++, 1, "%s", mesg);
                wrefresh(chat_win);
            }
        }
        waitpid(pid, NULL, 0);
    }

    // 종료 전 cleanup
    delwin(chat_win);
    delwin(input_win);
    endwin();
}

int main(int argc, char **argv)
{
    struct sockaddr_in servaddr;
    //pid_t pid; 
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

    // ncurses 초기화
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    // 창을 화면의 높이에 맞게 설정
    int height, width;
    getmaxyx(stdscr, height, width);

    WINDOW *chat_win = newwin(height - 5, width, 0, 0); // 채팅 표시 박스
    WINDOW *input_win = newwin(5, width, height - 5, 0); // 입력 박스

    // UI 그리기
    draw_chat_ui(chat_win, input_win);

    int highlight = 0; // 현재 선택된 메뉴 항목
    int op;

    while (1) {
        display_menu(highlight);
        int choice = getch();

        switch (choice) {
            case KEY_UP:
                highlight = (highlight == 0) ? 5 : highlight - 1;
                break;
            case KEY_DOWN:
                highlight = (highlight == 5) ? 0 : highlight + 1;
                break;
            case 10: // Enter 키
                clear();
                refresh();
                op = highlight + 1; // 메뉴 선택
                break;
            default:
                continue;
        }

        switch (op) {
            case 1: // 로그인
                if(strlen(user_id) != 0) {
                    //printw("로그인 상태입니다. ID : %s\n", user_id);
                    //printw("\033[32m[Press Enter]\033[0m\n");
                    getch();
                    clear();  // Enter 후 화면 지우기
                    refresh();  // 화면 리프레시
                    continue;
                }
                // 새 창에서 사용자 ID 입력
                WINDOW *login_win = newwin(5, 40, 10, 10);
                box(login_win, 0, 0);
                mvwprintw(login_win, 1, 1, "USER ID: ");
                

                // 커서 보이게 설정
                curs_set(1);
                // 입력한 문자가 화면에 보이게 설정
                echo();
                mvwgetnstr(login_win, 1, 10, user_id, MAX_ID_LEN); // 사용자 ID 입력
                
                sprintf(mesg, "LOGIN:%s", user_id);
                send(ssock, mesg, strlen(mesg), 0);
                
                //mvwprintw(login_win, 2, 1, "[Press Enter]");
                wrefresh(login_win);
                // 서버로부터 응답 받기
                memset(mesg, 0, BBUFSIZ);
                if (recv(ssock, mesg, BBUFSIZ, 0) > 0) {
                    //printw("서버 응답: %s\n", mesg);
                    mvwprintw(login_win, 2, 1, "Server On : %s",mesg);
                    mvwprintw(login_win, 3, 1, "[Press Enter]");
                    wrefresh(login_win);
                }
                
                
                delwin(login_win);
                getch();
                clear();  // Enter 후 화면 지우기
                refresh();  // 화면 리프레시
                break;
                
            case 2: // 채팅하기
                if (strlen(user_id) == 0) {
                    //printw("Login first.\n");
                    getch();
                    clear();
                    refresh();
                    continue;
                }

                start_chat();
                /*
                if (strlen(user_id) == 0) {
                    printw("Login first.\n");
                    getch();
                    clear();
                    refresh();
                    continue;
                }

                // 상단 채팅 내용 출력 창 (줄 수를 조정할 수 있음)
                WINDOW *chat_win = newwin(20, 50, 2, 5);  // (높이, 너비, 시작 y, 시작 x)
                box(chat_win, 0, 0); // 테두리 그리기
                wrefresh(chat_win);

                // 하단 채팅 입력 창
                WINDOW *input_win = newwin(5, 50, 22, 5); // (높이, 너비, 시작 y, 시작 x)
                box(input_win, 0, 0);
                mvwprintw(input_win, 1, 1, "> ");
                wrefresh(input_win);

                curs_set(1); // 커서 보이게 설정
                echo(); // 입력된 문자가 화면에 보이게 설정

                pid = fork();
                if (pid < 0) {
                    perror("Error");
                } else if (pid == 0) {
                    // 자식 프로세스: 메시지 전송
                    while (1) {
                        char temp[MAX_MSG_LEN];
                        wmove(input_win, 1, 25); // 입력 위치 조정
                        wclrtoeol(input_win); // 이전 입력 지우기
                        wrefresh(input_win);

                        wgetnstr(input_win, temp, MAX_MSG_LEN); // 입력 받기
                        temp[strcspn(temp, "\n")] = 0; // 개행 문자 제거

                        if (strcmp(temp, "q") == 0) {
                            send(ssock, "q", 1, 0);
                            exit(0);
                        }

                        // 메시지 보내기
                        sprintf(mesg, "%s : %s", user_id, temp);
                        send(ssock, mesg, strlen(mesg), 0);
                    }
                } else {
                    // 부모 프로세스: 메시지 수신
                    while (1) {
                        memset(mesg, 0, BBUFSIZ);
                        if (recv(ssock, mesg, BBUFSIZ, 0) <= 0) {
                            perror("recv()");
                            kill(pid, SIGTERM);
                            break;
                        } else if (strncmp(mesg, "Client", 5) == 0) {
                            mvwprintw(chat_win, 1, 1, "채팅 종료");
                            mvwprintw(chat_win, 2, 1, "엔터를 눌러주세요.");
                            wrefresh(chat_win);
                            break;
                        } else {
                            // 채팅 내용 출력
                            wprintw(chat_win, "%s\n", mesg);
                            wrefresh(chat_win);
                        }
                    }
                    waitpid(pid, NULL, 0);
                }

                // 윈도우 삭제 및 리셋
                delwin(chat_win);
                delwin(input_win);
                clear();
                refresh();
                getch();  // 대기
                continue;
                */
            case 3: // 로그아웃
                if (strlen(user_id) == 0) {
                    printw("You are not logged in.\n");
                    getch();
                    continue;
                }
                sprintf(mesg, "LOGOUT:%s", user_id);
                send(ssock, mesg, strlen(mesg), 0);
                memset(user_id, 0, MAX_ID_LEN);
                printw("로그아웃되었습니다.\n");

                // 서버로부터 응답 받기
                memset(mesg, 0, BBUFSIZ);
                if (recv(ssock, mesg, BBUFSIZ, 0) > 0) {
                    printw("서버 응답: %s\n", mesg);
                }
                getch();
                break;
            case 4: // 메시지 검색
                printw("검색할 사용자 ID 입력: ");
                char search_id[MAX_ID_LEN];
                fgets(search_id, MAX_ID_LEN, stdin);
                search_id[strcspn(search_id, "\n")] = 0; // 개행 문자 제거

                // 서버에 검색 요청 전송
                sprintf(mesg, "SEARCH:%s", search_id);
                send(ssock, mesg, strlen(mesg), 0);

                // 서버로부터 검색 결과 수신
                memset(mesg, 0, BBUFSIZ);
                if (recv(ssock, mesg, BBUFSIZ, 0) > 0) {
                    printw("검색 결과:\n%s\n", mesg);
                }
                
                getch();
                break;
            case 5: // 파일 전송
                char filename[BUFSIZ];
                printw("전송할 파일 이름을 입력하세요: ");
                fgets(filename, BUFSIZ, stdin);
                filename[strcspn(filename, "\n")] = 0;  // 개행 문자 제거
                send_file(ssock, filename);
                getch();
                break;
            case 6: // 종료
                sprintf(mesg, "quit");
                send(ssock, mesg, strlen(mesg), 0);
                cleanup();
                break;
            default:
                //printw("잘못된 선택입니다. 다시 선택해주세요.\n");
                //getchar();
                continue;
        }
    }

    return 0;
}