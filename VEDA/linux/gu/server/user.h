#ifndef _USER_H_
#define _USER_H_

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#include <pthread.h>

// #define MAX_CLIENTS 10
#define BUF_SIZE 1024
#define CSV_FILE "users.csv"
#define MAX_CLIENTS 100

int pipe_fd[MAX_CLIENTS][2];

typedef struct {
	char id[20];
	char password[20];
} UserData;

int signup(UserData *user_data);
int login(UserData *user_data);

#endif // _USER_H_
