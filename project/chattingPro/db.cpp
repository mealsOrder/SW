#include <mysql/mysql.h>
#include <iostream>
#include <string>

void connect_to_db() {
    MYSQL* conn;
    conn = mysql_init(0);

    // 데이터베이스에 연결
    conn = mysql_real_connect(conn, "localhost", "root", "password", "chat_db", 3306, NULL, 0);

    if (conn) {
        std::cout << "데이터베이스 연결 성공\n";
    } else {
        std::cout << "데이터베이스 연결 실패\n";
    }

    // SQL 쿼리 수행 등...
    mysql_close(conn);
}

int main() {
    connect_to_db();
    return 0;
}
