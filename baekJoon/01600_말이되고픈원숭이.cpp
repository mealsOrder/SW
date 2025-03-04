#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int MX = 201;
int H,W,K;
int map[MX][MX];
int dist[31][MX][MX];

int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { 1, -1, 2, -2, 2, -2, 1, -1 };
int ddx[] = {0,0,1,-1};
int ddy[] = {1,-1,0,0};

void BFS(int x,int y,int k){
    queue<pair<int,pair<int,int> >>q;
    q.push({k,{x,y}});
    dist[k][x][y] = 1;
    

    while(!q.empty()){
        int curK = q.front().first;
        int curX = q.front().second.first;
        int curY = q.front().second.second;
        q.pop();

        if (curX == H - 1 && curY == W - 1) {
            cout << dist[curK][curX][curY] - 1 << '\n';
            return;
        }

        if(curK < K){
            for(int i=0;i<8;i++){
                int nk = curK +1;
                int nx = curX + dx[i];
                int ny = curY + dy[i];

                if(nx>=0&&nx<H&&ny>=0&&ny<W&&!map[nx][ny]&&!dist[nk][nx][ny] ){
                    if (dist[nk][nx][ny] == 0 || dist[nk][nx][ny] > dist[curK][curX][curY] + 1) {
                        dist[nk][nx][ny] = dist[curK][curX][curY] + 1;
                        q.push({nk, {nx, ny}});
                    }
                }
            }
        }
        for(int i=0;i<4;i++){
            int nx = curX + ddx[i];
            int ny = curY + ddy[i];

            if(nx>=0&&nx<H&&ny>=0&&ny<W&&!map[nx][ny]){
                if(dist[curK][nx][ny] == 0 || dist[curK][nx][ny] > dist[curK][curX][curY] + 1) {
                    dist[curK][nx][ny] = dist[curK][curX][curY] + 1;
                    q.push({curK, {nx, ny}});
                }
            }
        }
    }

    cout << -1 << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> K >> W >> H;

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> map[i][j];
        }
    }

    BFS(0,0,0);
    
    return 0;
}