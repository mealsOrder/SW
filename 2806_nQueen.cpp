#include <iostream>
#include <cstring>
using namespace std;

int T, N; // 테스트 케이스 수와 N-Queen 문제의 크기
int board[15]; // 각 행의 퀸의 열 위치를 저장
int count; // 경우의 수

// 현재 행의 퀸이 이전 행들의 퀸들과 충돌하는지 확인하는 함수
bool isValid(int x) {
    for (int i = 0; i < x; i++) {
        // 같은 열 또는 대각선에 퀸이 있는 경우 false 반환
        if (board[i] == board[x] || abs(board[i] - board[x]) == x - i)
            return false;
    }
    // 충돌이 없는 경우 true 반환
    return true;
}

// 백트래킹을 통해 N-Queen 문제를 해결하는 함수
void backtrack(int x) {
    if (x == N) { // N개의 퀸을 모두 배치한 경우
        count++; // 경우의 수 증가
        return;
    }

    for (int j = 0; j < N; j++) { // 각 열을 검사
        board[x] = j; // 현재 행의 퀸을 j열에 배치
        if (isValid(x)) // 이전 행들과 충돌하지 않으면
            backtrack(x + 1); // 다음 행으로 진행
    }
}

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        count = 0;
        memset(board, 0, sizeof(board)); // 초기화
        backtrack(0); // 백트래킹 시작
        cout << "#" << tc << " " << count << "\n";
    }
    return 0;
}