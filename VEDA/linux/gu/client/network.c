#include "network.h"


// 서버에 연결하는 함수
int connect_to_server(const char *ip, int port) {
    int sock;
    struct sockaddr_in serv_addr;

    // 1. 소켓 생성
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket() error");
        exit(1);
    }

    // 2. 서버 주소 설정
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip); 
    serv_addr.sin_port = htons(port);          

    // 3. 서버에 연결 요청
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect () error, server is not launched ");
        exit(1);
    }

    return sock;
}

void handle_signal(int sig) {
    // 파이프에서 서버 응답 읽기 (논블로킹 모드에서 시도)
    int n = read(pipe_fds[0], global_buffer, sizeof(global_buffer));
    if (n > 0) {
        global_buffer[n] = '\0';  // null-terminate the string
        update_needed = true;
    } else if (n == -1 && errno != EAGAIN && errno != EWOULDBLOCK) {
        perror("read() error");
    }
}


void request_response() {
    kill(getppid(), SIGUSR2);  // SIGUSR2 시그널로 부모에게 요청을 보냄
}

// 데이터를 서버로 전송하는 함수
void send_data(int sock, UserData *user_data, const char *command) {
    // 1. 유저 데이터 전송 (ID와 비밀번호)
    write(sock, user_data, sizeof(UserData));

    // 2. 명령어 전송 (signup 또는 login)
    write(sock, command, strlen(command) + 1); // +1은 NULL 문자 포함을 위해
}

void send_only_cmd_data(int sock, const char *command)
{
    write(sock, command, strlen(command));  // 종료 문자(\0)를 포함하지 않고 전송
}

void send_message(int sock, const char *message)
{
	write(sock, message, strlen(message) + 1);
}

// 서버로부터 응답을 받는 함수
int receive_response(int sock) {
    int response_code;

    // 1. 서버로부터 응답 읽기
    read(sock, &response_code, sizeof(int));
    if (response_code == -1) {
        perror("read() error");
        exit(1);
    }

    // message[str_len] = 0; // null-terminate the message
	return response_code;
    // printf("Server Response: %s\n", message);
}

void receive_msg_response(int sock) {
    char buffer[BUFFER_SIZE];
    int str_len;

    // 서버로부터 메시지 읽기
    str_len = read(sock, buffer, sizeof(buffer) - 1);
    if (str_len <= 0) {
        perror("read() error or connection closed");
        exit(1);
    }

    buffer[str_len] = '\0';  // 문자열 종료 처리

    // 파이프를 통해 자식에게 데이터 전송
    write(pipe_fds[1], buffer, str_len + 1);  // +1 to include null terminator
    kill(child_pid, SIGUSR1);  // 자식 프로세스에 시그널 전송
}



// 소켓 연결을 닫는 함수
void close_connection(int sock) {
    close(sock);
}

