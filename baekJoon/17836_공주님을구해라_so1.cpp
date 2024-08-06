#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 101;
int N,M,T;
int map[MX][MX];
int dist[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ans = 10001;
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dist[i][j] = -1;
        }
    }
}

void BFS(int x,int y){
    queue<pair<int,int>>q;
    dist[x][y] = 0;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];
            
            if(nx>=0&&nx<N&&ny>=0&&ny<M&&dist[nx][ny]<0){
                if(map[nx][ny] == 1) continue;

                dist[nx][ny] = dist[curX][curY]+1;
                q.push({nx,ny});
                
                // 맨허튼 거리 : |x1-(N-1)| + |y1-(M-1)|
                // 검을 먹으면 검의 위치(x1,y1) -> 도착(N-1,M-1)
                // 바로 간다고 생각 하면 코드를 아주 쉽게 짤 수 있음!
                if(map[nx][ny] == 2){
                    ans = min(ans,dist[nx][ny] + (N-nx-1) + (M-ny-1));
                }
                
            }

        }

    }
    if(dist[N-1][M-1] > 0)ans = min(ans,dist[N-1][M-1]);
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> T;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
    init();
    BFS(0,0);

    if(ans > T)cout << "Fail\n";
    else cout << ans <<'\n';

	return 0;
}