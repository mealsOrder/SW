#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int MX = 501;
int N,M;
int map[MX][MX];
bool vis[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int maxSum = 0;
void DFS(int x,int y,int cnt,int sum){
    if(cnt == 4){
        maxSum = max(maxSum,sum);
        return;
    }

    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0&&nx<N&&ny>=0&&ny<M&&!vis[nx][ny]){
            vis[nx][ny]=true;
            DFS(nx,ny,cnt+1,sum+map[nx][ny]);
            vis[nx][ny]=false;
        }
    }
}
void tShape(int x,int y){
    // ㅜ 모양
    if(x>=0 && x<N-1&&y>=1&&y<M-1){
        int hap = map[x][y-1]+map[x][y]+map[x][y+1]+map[x+1][y];
        maxSum = max(maxSum,hap);
    }
    // ㅗ 모양
    if(x>=1 && x<N && y>=1 && y<M-1){
        int hap = map[x][y-1]+map[x][y]+map[x][y+1]+map[x-1][y];
        maxSum = max(maxSum,hap);
    }
    // ㅓ 모양
    if(x>=1 && x<N-1 && y>=1 && y<M){
        int hap = map[x-1][y]+map[x][y]+map[x+1][y]+map[x][y-1];
        maxSum = max(maxSum,hap);
    }
    // ㅏ 모양
    if(x>=1 && x<N-1 && y>=0 && y<M-1){
        int hap = map[x-1][y]+map[x][y]+map[x+1][y]+map[x][y+1];
        maxSum = max(maxSum,hap);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >>N>>M;

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

    cout << maxSum << '\n';

    return 0;
}