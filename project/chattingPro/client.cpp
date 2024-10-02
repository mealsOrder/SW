#include <iostream>
#include <thread>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

void receive_messages(int client_socket) {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        
        if (bytes_received > 0) {
            std::cout << "서버로부터 수신: " << buffer << std::endl;
        }
    }
}

int main() {
    int client_socket;
    struct sockaddr_in server_addr;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
        std::cout << "서버에 연결됨\n";

        std::thread(receive_messages, client_socket).detach();  // 수신 쓰레드

        char message[1024];
        while (true) {
            std::cout << "메시지 입력: ";
            std::cin.getline(message, sizeof(message));
            send(client_socket, message, sizeof(message), 0);
        }
    } else {
        std::cout << "서버 연결 실패\n";
    }

    close(client_socket);
    return 0;
}
