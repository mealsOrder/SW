#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MX = 501;

int N;
int board[MX][MX];
int dp[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int DFS(int x,int y){
    if(dp[x][y])return dp[x][y];
    dp[x][y]=1;

    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>=0&&nx<N&&ny>=0&&ny<N&&board[x][y]<board[nx][ny]){
            dp[x][y] = max(dp[x][y], DFS(nx,ny)+1);
        }
    }
    return dp[x][y];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int a = DFS(i,j);
            ans = max(ans,a);
        }
    }
    cout << ans << '\n';
    return 0;
}
