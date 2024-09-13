#ifndef NETWORK_H
#define NETWORK_H

#include <arpa/inet.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>   // fcntl() 함수 사용
#include <errno.h>   // errno 처리
#include <stdbool.h>

#define BUFFER_SIZE 1024

// 유저 정보를 저장하는 구조체 정의
typedef struct {
    char id[20];
    char password[20];
} UserData;

int pipe_fds[2];  // 파이프용 파일 디스크립터
pid_t child_pid;
char global_buffer[BUFFER_SIZE];
bool update_needed;

// 함수 선언
int connect_to_server(const char *ip, int port);
void handle_signal(int sig);
void request_response();
void send_data(int sock, UserData *user_data, const char *command);
void send_only_cmd_data(int sock, const char *command);
void receive_msg_response(int sock);
int receive_response(int sock);
void close_connection(int sock);
void send_message(int sock, const char *message);


#endif

