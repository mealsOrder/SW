#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int MX = 101;
const int INF = 987987987;

int N, M, T;
int map[MX][MX];
int dist[MX][MX][2];    // dist[][][0] : 벽을 돌아가야하는 거리
                        // dist[][][1] : 벽을 뚫고 갈수 있는 거리
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

queue<pair<pair<int,int>,int>>q;    // 다음에는 turple로 작성해보자!
void BFS(int x,int y,int w){       
    q.push({{x,y},w});
    dist[x][y][w] = 0;

    while(!q.empty()){
        int curX = q.front().first.first;   // 현재x
        int curY = q.front().first.second;  // 현재y
        int curW = q.front().second;        // 검을 주웠는지 못주웠는지
        q.pop();

        // 상하좌우 네 방향으로 좌표 값 변화를 준다
        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            // 유효 범위에 들어오지 않으면 pass
            if (nx<0||nx>=N||ny<0||ny>=M) continue;

            // 거리 값이 -1 아니면 이미 방문 했다는 뜻으로 pass
            if(dist[nx][ny][curW] != -1) continue;

            // 검을 줍지 않았을땐 벽이 있으면 pass
            if(curW == 0 && map[nx][ny] == 1) continue;

            // map[nx][ny] == 2 에 도달했으면 nw값을 1로 바꿔준다
            // 아니면 nw 는 그냥 curW로 유지
            int nw = (map[nx][ny] == 2)?1:curW;

            // 거리 값 갱신
            dist[nx][ny][nw] = dist[curX][curY][curW]+1;
            q.push({{nx,ny},nw});
        }

    }

}

// 방문과 거리를 한번에 표시하기 위해 초기화를 해주는 함수
void init() {
    for (int i = 0; i <=N; i++) {
        for (int j = 0; j <=M; j++) {
            dist[i][j][0] = -1; // 검줍
            dist[i][j][1] = -1; // 겁 노줍
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;

    // 지도 입력 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    init();
    BFS(0,0,0); // (0,0,0)에서 BFS 시작
    // dist[N-1][M-1][0] 값이 -1 이면 도달 하지 못했다는 뜻
    int a1 = (dist[N-1][M-1][0] == -1)? INF : dist[N-1][M-1][0];
    int a2 = (dist[N-1][M-1][1] == -1)? INF : dist[N-1][M-1][1];
    int ans = min(a1,a2);   // 벽을 뚫고 가는것과 그냥 돌아가는것 중 짧은것을 저장
    if(ans>T)cout << "Fail\n";
    else cout << ans;

    return 0;
}
