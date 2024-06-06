#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 101;
int N,M,H;
int map[MX][MX][MX];
int dist[MX][MX][MX];
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
queue<pair<pair<int,int>,int>>q;
void BFS(){
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();

        for(int i=0;i<6;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            int nz = z+dz[i];
            
            if(nx<0||nx>=N||ny<0||ny>=M||nz<0||nz>=H)continue;
            if(map[nx][ny][nz] == -1)continue;
            if(dist[nx][ny][nz] >= 0)continue;
            dist[nx][ny][nz] = dist[x][y][z]+1;
            q.push({{nx,ny},nz});
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> M>>N>>H;

    for(int k=0;k<H;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin >> map[i][j][k];
                if(map[i][j][k] == 1){
                    dist[i][j][k] = 0;
                    q.push({{i,j},k});
                }
                if(map[i][j][k] == 0){
                    dist[i][j][k] = -1;
                }
            }
        }
    }
    BFS();
    int ans = 0;
    for(int k=0;k<H;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(dist[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
                ans = max(ans,dist[i][j][k]);
            }
        }
    }
    cout << ans;
    return 0;
}