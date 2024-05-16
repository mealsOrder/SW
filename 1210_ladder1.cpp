#include<iostream>
#include<cstring>
using namespace std;

int ladder[101][101]; // 100x100 크기의 사다리 정보를 저장할 2차원 배열

int dx[3] = {0, 0, -1}; // 상, 좌, 우 방향 이동을 위한 x 좌표 변화량
int dy[3] = {-1, 1, 0}; // 상, 좌, 우 방향 이동을 위한 y 좌표 변화량

// DFS(Depth-First Search) 알고리즘을 사용하여 사다리 탐색
int DFS(int a, int b) {
    int x = a; // 현재 x 좌표
    int y = b; // 현재 y 좌표
    
    while (1) { // 도착점(x == 0)에 도달할 때까지 반복
        if (x == 0) return y; // 도착점 도달 시 현재 y 좌표 반환
        for (int i = 0; i < 3; i++) { // 상, 좌, 우 방향 탐색
            int nx = x + dx[i]; // 다음 x 좌표
            int ny = y + dy[i]; // 다음 y 좌표

            // 다음 좌표가 사다리 범위를 벗어나거나 통로가 없는 경우 continue
            if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100) continue;
            if (ladder[nx][ny] == 0) continue;
            
            // 다음 좌표로 이동
            x = nx;
            y = ny;
            ladder[nx][ny] = 0; // 방문 표시
            break;
        }
    }
    return y;
}

int main(void) {
    int num;

    for (int T = 1; T <= 10; T++) { // 10번의 테스트 케이스 처리
        memset(ladder, 0, sizeof(int) * 101 * 101); // 사다리 정보 초기화
        cin >> num; // 테스트 케이스 번호 입력

        // 사다리 정보 입력
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> ladder[i][j];
            }
        }

        // 맨 아래 행 탐색하여 출발 지점 찾기
        for (int i = 0; i < 100; i++) {
            if (ladder[99][i] == 2) { // 도착점 찾기
                int ans = DFS(99, i); // DFS 알고리즘 실행
                cout << '#' << num << ' ' << ans << '\n'; // 결과 출력
                break;
            }
        }
    }
    return 0;
}