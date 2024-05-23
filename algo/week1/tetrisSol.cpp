#include <iostream>
using namespace std;

const int MAX = 20;
int board[MAX][MAX];

// 수평선의 개수를 확인하는 함수
int check(int R, int C) {
    int result = 0;
    // 각 행을 탐색
    for (int i = 0; i < C; i++) {
        int count = 0;
        for (int j = 0; j < R; j++) {
            if (board[i][j] == 1) {
                count++;
            }
        }
        if (count == R) { // 1인 원소가 열의 개수와 같다면
            result++; // 수평선의 개수 세어줌
        }
    }
    return result;
}

int main() {
    int R, C;
    cin >> R >> C;

    // 격자의 초기 상태 입력받기
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            cin >> board[i][j];
        }
    }

    int total = 0;
    int index = 0;
    for (int j = 0; j < R; j++) { // 각 열에서 탐색
        int now = C - 1; // 아무것도 채워져있지 않다면 맨 아래부터 채움

        for (int i = 0; i < C; i++) {
            if (board[i][j] == 1) { // 채워진게 있다면
                now = i - 1; // 그 위부터 채움
                break;
            }
        }

        if (now < 3) continue; // 테트리미노의 제일 아래가 3보다 작으면 채울 수 없음

        for (int i = 0; i < 4; i++) {
            board[now - i][j] = 1; // 테트리미노를 채워줌
        }

        if (total < check(R, C)) { // 수평선의 개수를 구해 최대값 구해줌
            total = check(R, C);
            index = j + 1; // 최대일 때의 열의 번호
        }

        for (int i = 0; i < 4; i++) {
            board[now - i][j] = 0; // 채운 테트리미노를 지워줌
        }
    }

    cout << index << " " << total << endl;
    return 0;
}