#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MX = 101;
int N, M;

// 각 방에 불이 켜져 있는지를 나타냄
bool light[MX][MX];

// 각 방을 방문했는지를 나타냄 (불이 켜졌다고 해서 방문 가능하진 않음)
bool vis[MX][MX];

// 각 방 (i, j)에서 스위치로 불을 켤 수 있는 다른 방들을 저장하는 인접 리스트
vector<pair<int, int>> adj[MX][MX];

// 4방향 이동을 위한 방향 벡터
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// 좌표가 맵 밖으로 나가는지 확인하는 함수 (Out Of Bounds)
bool OOB(int x, int y){
    return x < 1 || x > N || y < 1 || y > N;
}

// BFS로 (1,1)부터 탐색하며 방문할 수 있는 모든 방에 접근하고 불을 켬
void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;  // 시작 지점 방문 처리

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        int curX = cur.first;
        int curY = cur.second;

        // 현재 방에서 스위치를 눌러 불을 켤 수 있는 방들의 불을 킴
        for(int i = 0; i < adj[curX][curY].size(); i++){
            int a = adj[curX][curY][i].first;
            int b = adj[curX][curY][i].second;

            if(!light[a][b]){  // 아직 불이 꺼져 있다면
                light[a][b] = true;  // 불을 킴

                // 불이 켜진 방 (a,b)가 이미 방문된 방과 인접해 있다면 큐에 추가
                for(int dir = 0; dir < 4; dir++){
                    int nx = a + dx[dir];
                    int ny = b + dy[dir];
                    if(!OOB(nx, ny) && vis[nx][ny]){
                        vis[a][b] = true;  // 방문 가능 표시
                        q.push({a, b});    // 탐색 대기열에 추가
                        break;
                    }
                }
            }
        }

        // 현재 위치에서 4방향 인접한 방 중, 불이 켜져 있고 아직 방문하지 않은 방을 큐에 추가
        for(int dir = 0; dir < 4; dir++){
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];

            if(OOB(nx, ny)) continue;        // 범위 밖
            if(vis[nx][ny]) continue;        // 이미 방문
            if(!light[nx][ny]) continue;     // 불이 꺼진 방

            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;  // 방의 크기와 스위치 정보 개수 입력

    for(int i = 0; i < M; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        // (x,y) 방에서 (a,b) 방의 불을 켤 수 있음
        adj[x][y].push_back({a, b});
    }

    // (1,1)은 항상 불이 켜져 있으므로 시작점으로 설정
    light[1][1] = true;
    BFS(1, 1);  // BFS로 탐색 시작

    // 불이 켜진 방의 수 계산
    int ans = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(light[i][j]) ans++;

    cout << ans << '\n';
    return 0;
}
