#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <mutex>

std::vector<int> client_sockets;  // 클라이언트 소켓들 저장
std::mutex mtx;  // 쓰레드 동기화를 위한 뮤텍스

void handle_client(int client_socket) {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        
        if (bytes_received <= 0) {
            std::cout << "클라이언트 연결 종료\n";
            close(client_socket);
            break;
        }

        std::cout << "메시지 수신: " << buffer << std::endl;

        // 받은 메시지를 다른 클라이언트들에게 전달
        mtx.lock();
        for (int socket : client_sockets) {
            if (socket != client_socket) {
                send(socket, buffer, sizeof(buffer), 0);
            }
        }
        mtx.unlock();
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);
    
    std::cout << "서버 실행 중...\n";

    while (true) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        std::cout << "새로운 클라이언트 연결\n";
        
        mtx.lock();
        client_sockets.push_back(client_socket);
        mtx.unlock();

        std::thread(client_thread, handle_client, client_socket).detach();  // 클라이언트 쓰레드 생성
    }

    close(server_socket);
    return 0;
}
