#include "connect.h"
#include "user.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define PORT 12345
#define IP "127.0.0.1"



int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;

    signal(SIGCHLD, sigchld_handler);
    signal(SIGUSR1, sigusr1_handler);  // SIGUSR1 핸들러 설정

    // 서버 소켓 설정
    server_sock = setup_server(IP, PORT);

    while (1) {
        client_addr_size = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_size);

        if (client_sock == -1) {
            if (errno == EINTR)
                continue;  // 시그널로 인해 accept()가 중단되면 다시 시도
            perror("accept() error");
            continue;
        }

        // 파이프 생성
        // if (pipe(pipe_fd[client_sock]) == -1) {
        //     perror("pipe() error");
        //     close(client_sock);
        //     continue;
        // }

        pid_t pid = fork();

        if (pid == -1) {
            // fork 실패 처리
            perror("fork() error");
            close(client_sock);
            continue;
        } else if (pid == 0) {  // 자식 프로세스
            setpgid(0, 0);
            close(server_sock);  // 자식 프로세스는 서버 소켓을 닫음
            // close(pipe_fd[client_sock][1]);  // 부모의 쓰기 파이프 닫음
            handle_client(client_sock, client_addr);  // 클라이언트 처리
            close(client_sock);  // 클라이언트 소켓 닫음
            exit(0);  // 자식 프로세스 종료
        } else {  // 부모 프로세스
            add_client(client_sock, client_addr, pid);  // 클라이언트 추가
            // close(pipe_fd[client_sock][0]);  // 자식의 읽기 파이프 닫음
        }
    }

    close_connection(server_sock);
    return 0;
}