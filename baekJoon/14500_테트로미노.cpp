#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MX = 501;
int map[MX][MX];
bool vis[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int N,M,ans;

void DFS(int x,int y, int cnt,int hap){
    if(cnt == 4){
        ans = max(ans,hap);
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0&&nx<N&&ny>=0&&ny<M&&!vis[nx][ny]){
            vis[nx][ny] = true;
            DFS(nx,ny,cnt+1,hap+map[nx][ny]);
            vis[nx][ny] = false;
        }
    }
}
void tShape(int x,int y){
    // ㅓ
    if(x-1>=0&&x+1<N&&y-1>=0&&y<M){
        int hap = map[x][y]+map[x-1][y]+map[x+1][y]+map[x][y-1];
        ans = max(ans,hap);
    }
    // ㅏ
    if(x-1>=0&&x+1<N&&y>=0&&y+1<M){
        int hap = map[x][y]+map[x-1][y]+map[x+1][y]+map[x][y+1];
        ans = max(ans,hap);
    }

    // ㅗ
    if(x-1>=0&&x<N&&y-1>=0&&y+1<M){
        int hap = map[x][y]+map[x][y-1]+map[x][y+1]+map[x-1][y];
        ans = max(ans,hap);
    }
    // ㅜ
    if(x>=0&&x+1<N&&y-1>=0&&y+1<M){
        int hap = map[x][y]+map[x][y-1]+map[x][y+1]+map[x+1][y];
        ans = max(ans,hap);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            vis[i][j] = true;
            DFS(i,j,1,map[i][j]);
            vis[i][j] = false;
            tShape(i,j);
        }
    }
    cout << ans << '\n';
    return 0;
}