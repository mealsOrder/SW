#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int MX = 51;
int map[MX][MX];
bool vis[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ans;
int N,M,K;
void BFS(int x,int y){
    queue<pair<int,int>>q;
    if(vis[x][y])return;
    vis[x][y] = true;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M&&!vis[nx][ny]&&map[nx][ny]){
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        cin >> N>>M>>K;
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));

        for(int t=0;t<K;t++){
            int i,j;
            cin >> i >> j;
            map[i][j] = 1;
        }
        ans = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j] && !vis[i][j]){
                    BFS(i,j);
                    ans++;
                }
            }
        }
        cout << ans <<'\n';
    }

    return 0;
}