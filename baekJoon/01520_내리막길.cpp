#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
#include<climits>
using namespace std;

const int MX = 501;

int map[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dp[MX][MX];

int N,M;

int DFS(int x,int y){
    if(x == N-1 && y == M-1) return 1;

    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0&&nx<N&&ny>=0&&ny<M&& map[x][y] > map[nx][ny]){
            dp[x][y] += DFS(nx,ny);
        }
    }
    return dp[x][y];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));
    cout << DFS(0,0) << '\n';
    return 0;
}