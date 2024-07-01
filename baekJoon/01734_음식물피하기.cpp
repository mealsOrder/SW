#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
const int MX = 101;

int map[MX][MX];
bool vis[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ans;
int N,M,K;
int BFS(int x,int y){
    queue<pair<int,int>>q;
    int cnt = 1;
    q.push({x,y});
    vis[x][y]=true;

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=1&&nx<=N&&ny>=1&&ny<=M&&!vis[nx][ny]&&map[nx][ny]){
                vis[nx][ny] = true;
                q.push({nx,ny});
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N>>M>>K;

    for(int i=0;i<K;i++){ // 입력 조건 확인 잘 하기!!!
        int a,b;
        cin >> a >> b;
        map[a][b] = 1;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(!vis[i][j] && map[i][j]){
                ans = max(ans,BFS(i,j));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}