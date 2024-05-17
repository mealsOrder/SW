#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int MAX = 51; // 최대 배열 크기 상수 정의

int map[MAX][MAX]; // 밭의 정보를 저장할 2차원 배열
bool visited[MAX][MAX]; // 방문 여부를 저장할 2차원 배열
int M, N, K; // 밭의 크기와 배추 위치의 개수
int dx[4] = {0,0,1,-1}; // 상하좌우 방향 델타 값
int dy[4] = {1,-1,0,0};
vector<int> res; // 각 섬의 크기를 저장할 벡터
queue<pair<int,int>> q; // BFS 탐색을 위한 큐

// BFS 알고리즘을 이용하여 섬의 크기 계산
void BFS(int x, int y) {
    visited[x][y] = true; // 현재 위치 방문 처리
    q.push({x, y}); // 현재 위치를 큐에 삽입
    int cnt = 1; // 섬의 크기를 나타내는 변수

    while(!q.empty()) { // 큐가 빌 때까지 반복
        int curX = q.front().first; // 현재 노드의 x좌표
        int curY = q.front().second; // 현재 노드의 y좌표
        q.pop(); // 현재 노드 큐에서 제거

        // 상하좌우 방향으로 탐색
        for(int i=0; i<4; i++) {
            int nx = curX + dx[i]; // 다음 x좌표
            int ny = curY + dy[i]; // 다음 y좌표

            // 다음 좌표가 밭 범위 내이고, 배추가 있으며, 아직 방문하지 않은 경우
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true; // 다음 좌표 방문 처리
                q.push({nx, ny}); // 다음 좌표를 큐에 삽입
                cnt++; // 섬의 크기 증가
            }
        }
    }

    res.push_back(cnt); // 계산된 섬의 크기를 결과 벡터에 추가
}

int main() {
    int T; // 테스트 케이스의 개수
    cin >> T;

    for(int t=0; t<T; t++) {
        cin >> M >> N >> K; // 밭의 크기와 배추 위치의 개수 입력 받기
        memset(map, 0, sizeof(map)); // 밭의 정보 초기화
        memset(visited, false, sizeof(visited)); // 방문 여부 초기화
        res.clear(); // 결과 벡터 초기화

        // 배추 위치 입력 받기
        for(int i=0; i<K; i++) {
            int a, b;
            cin >> a >> b;
            map[b][a] = 1; // 배추가 있는 위치를 1로 표시
        }

        // 모든 위치에서 BFS 탐색 수행
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(map[i][j] && !visited[i][j]) {
                    BFS(i, j);
                }
            }
        }

        // 결과 출력
        cout << res.size() << endl;
    }

    return 0;
}