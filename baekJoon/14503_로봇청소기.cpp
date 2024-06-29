#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 51;
int map[MX][MX];
bool vis[MX][MX];
int N,M;
int x,y,d;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int cnt=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N>>M;
    cin >> x>>y>>d;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
    while(true){
        if(map[x][y] == 0) cnt++;
        map[x][y] = -1;
        bool cleaned = false;
        for(int i=0;i<4;i++){
            d = (d+3)%4;
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(map[nx][ny] == 0){
                x += dx[d];
                y += dy[d];
                cleaned=true;
                break;
            }
        }
        if(cleaned) continue;
        int bx = x-dx[d];
        int by = y-dy[d];
        if(map[bx][by] == 1) break;
        x -= dx[d];
        y -= dy[d];
    }
    cout << cnt << '\n';
    return 0;
}