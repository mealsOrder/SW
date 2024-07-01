#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 1001;
int N,M;
int map[MX][MX];
int dist[MX][MX][2]; // 0:벽을 부수지 않은 거리 1: 벽을 하나 부스고 지나가는 거리
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
queue<pair<pair<int,int>,int>>q;
int BFS(int x,int y){
    q.push({{x,y},0});
    dist[x][y][0] = 1;

    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int w = q.front().second;
        if(curX == N-1 && curY == M-1) return dist[curX][curY][w];
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M){
                if(map[nx][ny] == 0 && dist[nx][ny][w] == 0){
                    q.push({{nx,ny},w});
                    dist[nx][ny][w] = dist[curX][curY][w]+1;
                }
                else if(w==0 && map[nx][ny] == 1 && dist[nx][ny][1]==0 ){
                    q.push({{nx,ny},1});
                    dist[nx][ny][1] = dist[curX][curY][0] + 1;
                }
            }
        }

    }
    return -1;
}
int main(){

    cin >> N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%1d",&map[i][j]);
        }
    }
    int ans = BFS(0,0);
    cout << ans << '\n';

    return 0;
}