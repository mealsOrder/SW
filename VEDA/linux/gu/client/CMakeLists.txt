cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 및 C 표준 설정
project(chat_client C)

# C 표준 설정
set(CMAKE_C_STANDARD 11)

# ncurses 라이브러리 찾기
find_package(Curses REQUIRED)

# include 디렉토리 추가 (ui.h가 있는 위치)
include_directories(${CURSES_INCLUDE_DIR})

# 소스 파일 지정
set(SOURCES
    client.c
    ui.c
	network.c
)

# 실행 파일 생성
add_executable(chat_client ${SOURCES})

# ncurses 라이브러리 링크
target_link_libraries(chat_client ${CURSES_LIBRARIES})

