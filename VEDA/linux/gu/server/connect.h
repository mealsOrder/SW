// network.h
#ifndef CONNECT_H
#define CONNECT_H

#pragma once
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <fcntl.h>
#include "user.h"

#define MAX_CLIENTS 100
int pipe_fd[MAX_CLIENTS][2];

struct client_info {
    int sock_fd;                   // 클라이언트 소켓 파일 디스크립터
    struct sockaddr_in addr;       // 클라이언트 주소 정보
    char ip[INET_ADDRSTRLEN];      // 클라이언트 IP 주소
    int port;                      // 클라이언트 포트 번호
};

struct client_info clients[MAX_CLIENTS];


int setup_server(const char *ip, int port);
int receive_data(int sock, char *buffer, size_t size);
int send_msg_data(int sock, const char *message);
int send_flag_data(int sock, int code);
void close_connection(int sock);
void sigchld_handler(int sig);
void add_client(int client_sock, struct sockaddr_in client_addr, pid_t pid);
void remove_client(int client_sock);
void handle_client(int client_sock, struct sockaddr_in client_addr);
void update_clients_from_parent();
void sigusr1_handler(int sig);

#endif