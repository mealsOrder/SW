cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 및 C 표준 설정
project(chat_server C)

# C 표준 설정
set(CMAKE_C_STANDARD 11)

# 소스 파일 지정
set(SOURCES
	connect.c
	server.c
    user.c
)

# 실행 파일 생성
add_executable(chat_server ${SOURCES})

# ncurses 라이브러리 링크
target_link_libraries(chat_server)

