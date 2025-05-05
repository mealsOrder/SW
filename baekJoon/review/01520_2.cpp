#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
#include<climits>
using namespace std;

const int MX = 501;

int N,M;
int a[MX][MX];
int dp[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int DFS(int x, int y){
    if(dp[x][y] != -1) return dp[x][y]; // 
    if(x == N-1 && y == M-1) return 1;
    dp[x][y] = 0;

    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>=0&&nx<N&&ny>=0&&ny<M&&a[x][y] > a[nx][ny]){
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
            cin >> a[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << DFS(0,0) << '\n' ;

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}