#include "ui.h"

static int sock;

static char h_username[30]; 


void parent_signal_handler(int sig) {
    // 서버 응답을 수신
    receive_msg_response(sock);
}

// 메뉴 항목 정의
char *menu_choices[MENU_SIZE] = {
    "1. Create Chat",
    "2. Delete Room",
    "3. Chat Start",
    "4. Search Message",
    "5. Send File",
    "6. Exit"
};

char *auth_menu_choices[AUTH_MENU_SIZE] = {
    "1. Login",
    "2. Register"
};

// 윈도우 포인터 선언
WINDOW *header_win, *menu_win, *content_win, *footer_win, *auth_win;

// 윈도우 생성 및 초기화 함수
void init_windows() {
    header_win = newwin(3, COLS, 0, 0);                   
    menu_win = newwin(LINES - 6, 20, 3, 0);               
    content_win = newwin(LINES - 6, COLS - 20, 3, 20);  
    footer_win = newwin(3, COLS, LINES - 3, 0);           
}

// 헤더 출력 함수
void draw_header(WINDOW *header_win) {
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    wclear(header_win);
    mvwprintw(header_win, 1, 2, "Connection Info: [Connected] | User: %s | IP: 192.168.1.1 | Time : %02d/%02d %02d:%02d"
    , h_username, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min);
    mvwprintw(header_win, 0, 2, "Chat Terminal");
    box(header_win, 0, 0);
    wrefresh(header_win);
}

// 메뉴 출력 함수 (일반 및 AUTH WIN 공용)
void draw_menu(WINDOW *menu_win, char **choices, int n_choices, int highlight) {
    int x = 2, y = 2;
    box(menu_win, 0, 0);
    for (int i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) {
            wattron(menu_win, A_REVERSE); // 선택된 메뉴 강조
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        } else {
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        }
        y++;
    }
    wrefresh(menu_win);
};

void start_chat(WINDOW *content_win, UIState *state) {
    wrefresh(content_win);
    send_only_cmd_data(sock, "CHAT");
    if (!receive_response(sock))
        mvwprintw(content_win, 1, 2, "Server connected");
    else
        mvwprintw(content_win, 1, 2, "Server Disconnected");
    sleep(1);
    echo();
    char message[30];

    mvwprintw(content_win, 2, 2, "Room List (Press ESC to return to menu)");
    wrefresh(content_win);
    mvwprintw(content_win, 3, 2, "Message: ");

    if (pipe(pipe_fds) == -1) {  // 파이프 생성
        perror("pipe() error");
        exit(1);
    }

    child_pid = fork();  // 부모와 자식 프로세스 분리

    if (child_pid == -1) {
        perror("fork() error");
        exit(1);
    }

    if (child_pid == 0) {  // 자식 프로세스
        close(pipe_fds[1]);  // 자식은 쓰기용 파이프 닫기

        // 파이프 읽기용 디스크립터를 논블로킹 모드로 설정
        int flags = fcntl(pipe_fds[0], F_GETFL, 0);
        fcntl(pipe_fds[0], F_SETFL, flags | O_NONBLOCK);

        signal(SIGUSR1, handle_signal);  // 부모가 응답을 보낼 때의 시그널 핸들러 설정

        int ch;
        int line_index = 1;

        while (1) {
            // 키 입력 받음
            ch = wgetch(content_win);

            // ESC 키를 누르면 루프 탈출 (자식 프로세스 종료)
            if (ch == 27) {  // ESC 키의 ASCII 값은 27
                kill(getppid(), SIGKILL);  // 부모 프로세스 종료
                exit(0);  // 자식 프로세스 종료
            }

            // 메시지 입력 받음
            mvwprintw(content_win, line_index + 2, 2, "Message: ");
            mvwprintw(content_win, line_index + 2, 14, "%c", ch);
            wrefresh(content_win);

            // 나머지 메시지를 입력받음
            mvwgetnstr(content_win, line_index + 2, 15, message + 1, 29);  // 1번째 자리부터 입력받음
            message[0] = ch;  // 첫 입력된 문자 추가

            // 서버로 메시지 전송
            send_message(sock, message);

            // 부모에게 응답 요청 (SIGUSR2 시그널 보내기)
            request_response();

            // 입력된 메시지 출력
            wrefresh(content_win);

            // 논블로킹으로 부모로부터 응답 체크 (파이프에서 읽기 시도)
            handle_signal(SIGUSR1);

            // 서버 응답이 있으면 전역 버퍼(global_buffer)에 저장된 서버 응답을 출력
            if (update_needed) {
                mvwprintw(content_win, line_index + 4, 2, "%s\n", global_buffer);
                wrefresh(content_win);
                global_buffer[0] = '\0';  // 버퍼 비우기
                update_needed = false;  // 화면 갱신 플래그 초기화
                line_index += 2;  // 다음 라인으로 이동
            }

            line_index += 2;  // 다음 라인으로 이동
        }
    } else {  // 부모 프로세스
        close(pipe_fds[0]);  // 부모는 읽기용 파이프 닫기
        signal(SIGUSR2, parent_signal_handler);  // 자식이 요청을 보낼 때의 시그널 핸들러 설정

        while (1) {
            // 자식으로부터 시그널을 기다림
            pause();  // SIGUSR2 시그널을 기다림
        }
    }
}

void create_chat_room(WINDOW *content_win, UIState *state) {
    mvwprintw(content_win, 1, 2, "Create Room");
}

void delete_chat_room(WINDOW *content_win, UIState *state) {
	// send_data(sock, &userdata, "FILE");
	mvwprintw(content_win, 1, 2, "Delete Room");
    mvwprintw(content_win, 3, 2, "State is : %d", state->current_menu);
}

void search_chat_message(WINDOW *content_win, UIState *state) {
    int connect_code = 0;
    send_only_cmd_data(sock, "CHAT");
	mvwprintw(content_win, 1, 2, "Search chat message");
    mvwprintw(content_win, 1, 2, "Server Connected : %d",  connect_code);
    mvwprintw(content_win, 3, 2, "State is : %d", state->current_menu);
}

void send_file(WINDOW *content_win, UIState *state) {
	mvwprintw(content_win, 1, 2, "Send File");
    mvwprintw(content_win, 3, 2, "State is : %d", state->current_menu);
}



// 콘텐츠 영역 출력 함수
void draw_content(WINDOW *content_win, int current_menu, UIState *state) {
    wclear(content_win);
    box(content_win, 0, 0);
    switch (current_menu) {
        case 1:
            create_chat_room(content_win, state);  // UIState 추가
            break;
        case 2:
            delete_chat_room(content_win, state);
            break;
        case 3:
            start_chat(content_win, state);
            break;
        case 4:
            search_chat_message(content_win, state);
            break;
        case 5:
            send_file(content_win, state);
            break;
        default:
            mvwprintw(content_win, 1, 2, "Unknown menu selected.");
            break;
    }
    wrefresh(content_win);
}

// 푸터 출력 함수
void draw_footer(WINDOW *footer_win) {
    wclear(footer_win);
    mvwprintw(footer_win, 1, 2, "Press UP/DOWN to navigate, ENTER to select");
    box(footer_win, 0, 0);
    wrefresh(footer_win);
}

// 입력 이벤트 처리 함수
void handle_input(int ch, UIState *state, int menu_size) {
    switch (ch) {
        case KEY_UP:
            if (state->highlight == 1)
                state->highlight = menu_size;
            else
                --state->highlight;
            break;
        case KEY_DOWN:
            if (state->highlight == menu_size)
                state->highlight = 1;
            else
                ++state->highlight;
            break;
        case 10: // Enter key
            state->current_menu = state->highlight;
            break;
        default:
            break;
    }
}

// 로그인 화면 출력 함수
void draw_login_screen(WINDOW *win, UIState *state) {
	UserData userdata;
    char username[30];
    char password[30];

    // 로그인 창 표시
    wclear(win);
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "Login");
    mvwprintw(win, 3, 2, "Username: ");
    mvwprintw(win, 4, 2, "Password: ");
    
    // 사용자로부터 아이디와 패스워드 입력받기
    echo(); // 입력 보이기
    mvwgetnstr(win, 3, 12, username, 30);
    noecho(); // 비밀번호는 입력 숨기기
    mvwgetnstr(win, 4, 12, password, 30);

	memcpy(userdata.id, username, sizeof(userdata.id));
	memcpy(userdata.password, password, sizeof(userdata.password));

	send_data(sock, &userdata, "login");
	if(receive_response(sock)==0) {
		mvwprintw(win, 6, 2, "Login Successful!");
        memcpy(h_username, userdata.id, sizeof(h_username));
		state->logged_in = 1;
	} else {
		mvwprintw(win, 6, 2, "Invalid credentials. Try again");
		state->logged_in = 0;
	}
	 
    wrefresh(win);

    // 로그인 처리 대기
    sleep(1);

    // 로그인 실패 시 다시 auth 메뉴로 돌아가기
    if (!state->logged_in) {
        show_auth_menu(state);
    }
}

// 회원가입 화면 출력 함수
void draw_register_screen(WINDOW *win, UIState *state) {
	UserData userdata;

    char username[20];
    char password[20];

    // 회원가입 창 표시
    wclear(win);
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "Register");
    mvwprintw(win, 3, 2, "New Username: ");
    mvwprintw(win, 4, 2, "New Password: ");
    
    // 사용자로부터 아이디와 패스워드 입력받기
    echo(); // 입력 보이기
    mvwgetnstr(win, 3, 16, username, 30);
    mvwgetnstr(win, 4, 16, password, 30);
	
	//회원가입 통신
	memcpy(userdata.id, username, sizeof(userdata.id));
	memcpy(userdata.password, password, sizeof(userdata.password));

	send_data(sock, &userdata, "signup");
	if(receive_response(sock)==0) {
        mvwprintw(win, 6, 2, "Registration successful!");
    }
	    
	else mvwprintw(win, 6, 2, "Registration Server Error!");
    wrefresh(win);

    // 처리 대기
    sleep(1);

    // 회원가입 완료 후 다시 auth 메뉴로 돌아가기
    show_auth_menu(state);
}

void show_auth_menu(UIState *state) {
    // auth_win이 이미 존재할 경우 삭제하고 NULL로 초기화
    if (auth_win != NULL) {
        delwin(auth_win);
        auth_win = NULL;
    }

    // state가 NULL인지 확인한 후 처리 (추가적인 보호)
    if (state != NULL) {
        auth_win = newwin(10, 40, (LINES - 10) / 2, (COLS - 40) / 2);  // 중앙에 auth 메뉴 창 생성
        keypad(auth_win, TRUE);  // 새로운 창에 대해 키보드 입력 활성화
        state->highlight = 1;    // 기본 하이라이트는 첫 번째 메뉴로 설정
    }

    int ch;
    while (1) {
        // 메뉴 그리기
        draw_menu(auth_win, auth_menu_choices, AUTH_MENU_SIZE, state->highlight);
        ch = wgetch(auth_win);  // 키 입력 받기
        handle_input(ch, state, AUTH_MENU_SIZE);  // 입력 처리

        if (ch == 10) {  // Enter 키가 눌리면
            if (state->highlight == 1) {
                // 로그인 화면으로 전환
                draw_login_screen(auth_win, state);
                
                // 로그인 후에 state->logged_in이 1로 설정되었는지 확인
                if (state != NULL && state->logged_in == 1) {
                    break;  // 로그인 성공 시 루프 탈출
                }
            } else if (state->highlight == 2) {
                // 회원가입 화면으로 전환
                draw_register_screen(auth_win, state);

                // 회원가입 후 로그인 화면을 다시 표시하지 않고 바로 메인 페이지로 넘어가도록 설정
                state->logged_in = 1;  // 회원가입 후 바로 로그인된 상태로 설정
                break;  // 메인 페이지로 넘어가기 위해 루프 탈출
            }
        }
    }

    delwin(auth_win);  // 마지막에 auth_win 삭제
}

// 로그인 완료 후 기존 레이아웃 불러오기
void show_main_ui(UIState *state) {
    init_windows();
    update_layout(state);  // 로그인 후 메인 화면 출력
}

// 전체 레이아웃 갱신 함수
void update_layout(UIState *state) {
    draw_header(header_win);
    draw_menu(menu_win, menu_choices, MENU_SIZE, state->highlight);
    draw_content(content_win, state->current_menu, state);
    draw_footer(footer_win);
}


void start_menu() {
    sock = connect_to_server("127.0.0.1", 12345);
    
    // UIState에서 하이라이트는 첫 번째 메뉴가 아닌 2번 메뉴가 하이라이트되도록 설정
    UIState state = {1, 1, 0};  // current_menu, highlight, logged_in 초기화

    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);

    show_auth_menu(&state);

    if (state.logged_in) {
        show_main_ui(&state);  // 메인 UI 출력
    }

    int ch;
    keypad(menu_win, TRUE);

    // 메인 메뉴 루프
    while (1) {
        update_layout(&state);  // 레이아웃 갱신 (하이라이트 반영)

        ch = wgetch(menu_win);  // 키 입력 받기
        handle_input(ch, &state, MENU_SIZE);  // 입력 처리
        update_layout(&state);  // 다시 레이아웃 갱신

        if (state.current_menu == MENU_SIZE) {  // 종료 선택시 루프 탈출
            break;
        }
    }

    endwin();  // ncurses 종료
}



