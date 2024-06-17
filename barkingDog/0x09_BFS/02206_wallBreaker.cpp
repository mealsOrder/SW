#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;
const int MX = 1001;
int map[MX][MX];
int dist[MX][MX][2];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int N,M;
int ans;
queue<tuple<int,int,int>>q;
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }
}
int BFS(){
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;
    q.push({0,0,0});
    while(!q.empty()){
        int x,y,w;
        tie(x,y,w) = q.front();
        if(x == N-1 && y == M-1) return dist[x][y][w];
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx<0||nx>=N||ny<0||ny>=M)continue;
            if(map[nx][ny] == 0 && dist[nx][ny][w] == -1){
                dist[nx][ny][w] = dist[x][y][w] + 1;
                q.push({nx,ny,w});
            }
            if(!w && map[nx][ny] == 1 && dist[nx][ny][1] == -1){
                dist[nx][ny][1] = dist[x][y][w] + 1;
                q.push({nx,ny,1});
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
    init();
    ans = BFS();
    cout << ans << '\n';
    return 0;
}