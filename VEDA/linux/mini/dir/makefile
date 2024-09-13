# Makefile

# 컴파일러와 플래그 설정
CC = gcc
CFLAGS = -Wall -g

# 실행 파일 이름
EXEC_CLIENT = c
EXEC_SERVER = s
EXEC_UI = u  # ui 실행 파일 이름 변경

# 소스 파일
SRCS_CLIENT = client.c
SRCS_SERVER = server.c
SRCS_UI = ui.c

# 오브젝트 파일
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_UI = $(SRCS_UI:.c=.o)

# 기본 타겟
all: $(EXEC_CLIENT) $(EXEC_SERVER) $(EXEC_UI)

# 클라이언트 실행 파일 만들기
$(EXEC_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^

# 서버 실행 파일 만들기
$(EXEC_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $@ $^

# UI 실행 파일 만들기 (ncurses 라이브러리 링크)
$(EXEC_UI): $(SRCS_UI)
	$(CC) $(CFLAGS) -o $@ $^ -lncurses

# 오브젝트 파일 만들기
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 클린 타겟
clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_UI) $(EXEC_CLIENT) $(EXEC_SERVER) $(EXEC_UI)

.PHONY: all clean