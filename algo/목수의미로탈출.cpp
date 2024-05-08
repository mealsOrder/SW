#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int N, M; // 지도의 세로 길이와 가로 길이
int map[MAX][MAX]; // 지도 정보
int dist[MAX][MAX][2]; // 각 좌표까지의 최단거리 정보 (0: 벽을 부수지 않은 경우, 1: 벽을 부수고 온 경우)
int dx[4] = {-1, 1, 0, 0}; // 상하좌우 이동 방향
int dy[4] = {0, 0, -1, 1};

int BFS() {
    // 큐와 초기 좌표 설정
    queue<pair<pair<int, int>, int>> q; // (x, y), 벽을 부수지 않았으면 0, 부쉈으면 1
    q.push({{N-1, 0}, 0}); // 출발점 (N-1, 0)에서 시작, 벽을 부수지 않은 상태
    dist[N-1][0][0] = 0; // 출발점 거리를 0로 설정

    while (!q.empty()) { // 큐가 빌 때까지 반복
        int x = q.front().first.first; // 현재 x 좌표
        int y = q.front().first.second; // 현재 y 좌표
        int wall = q.front().second; // 현재 벽을 부순 여부 (0: 부수지 않음, 1: 부숨)
        q.pop(); // 큐에서 현재 좌표 제거

        if (x == 0 && y == M-1) { // 도착점에 도달한 경우
            return dist[x][y][wall]; // 도착점까지의 거리 반환
        }

        // 상하좌우로 이동할 수 있는 좌표 확인
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; // 다음 x 좌표
            int ny = y + dy[i]; // 다음 y 좌표

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) { // 지도 범위 내에 있는 경우
                if (map[nx][ny] == 0 && dist[nx][ny][wall] == 0) { // 갈 수 있는 길이고, 아직 방문하지 않은 경우
                    q.push({{nx, ny}, wall}); // 큐에 추가
                    dist[nx][ny][wall] = dist[x][y][wall] + 1; // 거리 정보 갱신
                } else if (map[nx][ny] == 1 && wall == 0 && dist[nx][ny][1] == 0) { // 벽이지만 부술 수 있는 경우
                    q.push({{nx, ny}, 1}); // 큐에 추가
                    dist[nx][ny][1] = dist[x][y][0] + 1; // 벽을 부순 경우의 거리 정보 갱신
                }
            }
        }
    }

    return -1; // 도착점에 도달하지 못한 경우 -1 반환
}

int main() {
    // 지도 크기 입력받기
    cin >> N >> M;

    // 지도 정보 입력받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            dist[i][j][0] = dist[i][j][1] = 0; // 초기 거리를 0으로 설정
        }
    }

    // BFS 실행하여 최단거리 구하기
    int result = BFS();
    
	// 도착점에 도달하지 못한 경우 -1 출력
    cout << result << endl; // 도착점까지의 최단거리 출력
    

    return 0;
}