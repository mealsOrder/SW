#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
#include<climits>
using namespace std;

const int MX = 501;

int N;
int map[MX][MX];
int dp[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int DFS(int x,int y){
    if(dp[x][y]) return dp[x][y];
    dp[x][y]=1;

    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0&&nx<N&&ny>=0&&ny<N&& map[x][y] < map[nx][ny]){
            
            dp[x][y] = max(dp[x][y], DFS(nx,ny)+1);
        }
    }
    return dp[x][y];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
    
    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int a = DFS(i,j);           
            ans = max(ans,a);
            //cout << a << ' ' << i << ' ' << j <<'\n';
        }
    }

    cout << ans << '\n';

    return 0;
}