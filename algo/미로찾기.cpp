#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1001;

int N, M; // 지도의 세로 길이와 가로 길이
int map[MAX][MAX]; // 지도 정보
int dist[MAX][MAX]; // 각 좌표까지의 최단거리 정보
int dx[4] = {-1, 1, 0, 0}; // 상하좌우 이동 방향
int dy[4] = {0, 0, -1, 1};

int BFS() {
    // 큐와 출발점 좌표 초기화
    queue<pair<int, int>> q;
    q.push({N-1, 0});
    dist[N-1][0] = 0; // 출발점 거리를 0으로 설정

    while (!q.empty()) { // 큐가 빌 때까지 반복
        int x = q.front().first; // 현재 x 좌표
        int y = q.front().second; // 현재 y 좌표
        q.pop(); // 큐에서 현재 좌표 제거

        if (x == 0 && y == M-1) { // 도착점에 도달한 경우
            return dist[0][M-1]; // 도착점까지의 거리 반환
        }

        // 상하좌우로 이동할 수 있는 좌표 확인
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; // 다음 x 좌표
            int ny = y + dy[i]; // 다음 y 좌표

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && // 지도 범위 내에 있고
                map[nx][ny] == 0 && // 이동할 수 있는 부분이고
                dist[nx][ny] == -1) { // 아직 방문하지 않은 경우
                q.push({nx, ny}); // 큐에 추가
                dist[nx][ny] = dist[x][y]+1; // 거리 정보 갱신
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
            dist[i][j] = -1; // 초기 거리를 -1로 설정
        }
    }

    // BFS 실행하여 최단거리 구하기
    int result = BFS();
    cout << result << endl; // 결과 출력

    return 0;
}