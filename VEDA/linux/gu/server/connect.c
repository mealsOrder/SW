// network.c
#include "connect.h"

int global_client_sock;
int client_count = 0;


void sigchld_handler(int sig) {
    int saved_errno = errno;  // 시그널 핸들러에서 errno를 저장
    while (waitpid(-1, NULL, WNOHANG) > 0);  // 모든 종료된 자식 프로세스를 수거
    errno = saved_errno;  // 시그널 핸들러가 끝난 후 errno 복원
}

void sigusr1_handler(int sig) {
    // 시그널을 받으면 클라이언트 목록을 업데이트하는 함수 호출
    update_clients_from_parent();
}

// 소켓 생성 및 서버 연결 대기
int setup_server(const char *ip, int port) {
    int server_sock;
    struct sockaddr_in serv_addr;

    // 소켓 생성
    server_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket() error");
        exit(1);
    }

    // 주소 설정
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);  // IP 주소 설정
    serv_addr.sin_port = htons(port);           // 포트 번호 설정

    // 바인딩
    if (bind(server_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind() error");
        exit(1);
    }

    // 연결 대기
    if (listen(server_sock, 10) == -1) {

		perror("listen() error");
        exit(1);
    }

    printf("Server is listening on %s:%d\n", ip, port);
    return server_sock;
}

// 자식 프로세스가 부모로부터 클라이언트 목록을 받아 업데이트하는 함수
void update_clients_from_parent() {
    struct client_info new_client;
    int n;

    // 파이프 파일 디스크립터 확인
    if (pipe_fd[global_client_sock][0] < 0) {
        printf("Invalid pipe file descriptor: %d\n", pipe_fd[global_client_sock][0]);
        return;
    }

    printf("======================================\n");
    printf("client socket %d list : \n" , global_client_sock);

    // 파이프에서 클라이언트 목록을 읽어옴
    for (int i = 0; i < client_count; i++) {
        // 파이프에서 읽기
        n = read(pipe_fd[global_client_sock][0], &new_client, sizeof(struct client_info));
        
        if (n > 0) {
            // 읽은 클라이언트 정보를 출력
            printf("Received client info: IP = %s, Port = %d, SOCKET = %d\n",
                   new_client.ip, new_client.port, new_client.sock_fd);
        }
    }

    printf("======================================\n");
}


// 부모 프로세스가 자식 프로세스에게 클라이언트 목록을 보내는 함수
void send_clients_to_all_children() {
    // 모든 자식 프로세스에게 클라이언트 목록 전송
    for (int i = 0; i < client_count; i++) {
        for (int j = 0; j < client_count; j++) {
            write(pipe_fd[clients[j].sock_fd][1], &clients[i], sizeof(struct client_info));  // 클라이언트 정보를 구조체로 전송
        }
    }
    killpg(0, SIGUSR1);
}

//클라이언트 추가
void add_client(int client_sock, struct sockaddr_in client_addr, pid_t pid) {
    if (client_count < MAX_CLIENTS) {
        global_client_sock = client_sock;
        clients[client_count].sock_fd = client_sock;
        clients[client_count].addr = client_addr;
        inet_ntop(AF_INET, &client_addr.sin_addr, clients[client_count].ip, INET_ADDRSTRLEN);
        clients[client_count].port = ntohs(client_addr.sin_port);
        client_count++;

        printf("========================\n");
        printf("[INFO] New client added: IP = %s, Port = %d, SOCKET = %d\n", 
               clients[client_count - 1].ip, clients[client_count - 1].port, client_sock);

        printf("[INFO] Client count is : %d\n", client_count);
        printf("========================\n");
        
        // 클라이언트 목록이 업데이트되면 모든 자식에게 전송
        send_clients_to_all_children();
        
    } else {
        printf("[ERROR] Max clients reached, cannot add more clients\n");
    }
}

// 클라이언트 제거 함수
void remove_client(int client_sock) {
    int index = -1;
    printf("client_count is : %d", client_count);
    for (int i = 0; i < client_count; i++) {
        if (clients[i].sock_fd == client_sock) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("[INFO] Removing client: IP = %s, Port = %d, SOCKET = %d\n",
               clients[index].ip, clients[index].port, client_sock);

        // 클라이언트 리스트에서 제거
        close(clients[index].sock_fd);
        for (int i = index; i < client_count - 1; i++) {
            clients[i] = clients[i + 1];
        }
        client_count--;

        // 클라이언트 리스트 갱신 후 모든 자식 프로세스에 전송
        send_clients_to_all_children();
    } else {
        printf("[ERROR] Client not found for removal\n");
    }
}

void handle_client(int client_sock, struct sockaddr_in client_addr) {
    

    UserData user_data;
	
    char buffer[1024];
    char user_id[20];
    int logged_in = 0;
    int n;

    

    // 1. 로그인 처리
    while (!logged_in) {
        while((n = read(client_sock, &user_data, sizeof(UserData))) > 0 ) {
			char command[10];
			read(client_sock, command, sizeof(command));

			 if (strcmp(command, "signup") == 0) {
				  if (signup(&user_data)) {
					  int success_code = 0; // 성공
					  send_flag_data(client_sock, success_code);
					  printf("signup success\n");
				  } else {
					  int error_code = 1; // 회원가입 실패
					  send_flag_data(client_sock, error_code);
				  }
			  } else if (strcmp(command, "login") == 0) {
				  if (login(&user_data)) {
					  logged_in = 1;
					  int success_code = 0;
					  send_flag_data(client_sock, success_code);
                      printf("login success\n");
					  break;
					  
				  } else {
					  int error_code = 2; // 로그인 실패
					  send_flag_data(client_sock, error_code);
				  }
			  }
        }
    } 	

    // while (logged_in) {
    //     while((n = read(client_sock, buffer, sizeof(buffer))) > 0 ) {
    //         if (n == 0) {
    //             // 클라이언트가 연결을 정상 종료한 경우
    //             printf("[INFO] Client disconnected normally after login, closing socket: %d\n", client_sock);
    //             remove_client(client_sock);
    //             close(client_sock);
    //             exit(0);  // 자식 프로세스 종료
    //         } else if (n < 0) {
    //             if (errno == EINTR) {
    //                 // 클라이언트가 인터럽트를 발생시킨 경우
    //                 printf("[INFO] Client interrupted after login, closing socket: %d\n", client_sock);
    //             } else {
    //                 // 다른 종류의 에러 발생
    //                 perror("read error after login");
    //             }
    //             break;
    //         }
    //         // 정상적인 통신 처리 (예: 메시지 처리)
    //         printf("[INFO] Received message from client: %s\n", buffer);
    //     }
    // }
}

// 클라이언트로부터 데이터 읽기
int receive_data(int sock, char *buffer, size_t size) {
    int str_len = read(sock, buffer, size);
    if (str_len == -1) {
        perror("read() error");
        return -1;
    }
    buffer[str_len] = 0;  // NULL 종료
    return str_len;
}

// 클라이언트에게 데이터 보내기
int send_msg_data(int sock, const char *message) {
    return write(sock, message, strlen(message));
}

//클라이언트에게 플래그 보내기 
int send_flag_data(int sock, int code) {
	return write(sock, &code, sizeof(int));
}

// 클라이언트와의 연결 종료
void close_connection(int sock) {
    close(sock);
}


