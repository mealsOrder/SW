#include <bits/stdc++.h>
using namespace std;

const int MX = 101;
string board[MX];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool vis[MX][MX];
int n,m,cnt;

void init(int a,int b){
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            vis[i][j] = 0;
        }
    }
}

void bfs(int x,int y){
    queue<pair<int,int>>q;
    vis[x][y]=true;
    q.push({x,y});

    while(!q.empty()){
        int curX=q.front().first;
        int curY=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;

            if(board[nx][ny] != '.' && !vis[nx][ny]){
                vis[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        n=0,m=0,cnt=0;
        
        cin >> n >> m;
        init(n,m);
        for(int i=0;i<n;i++){
            cin >> board[i];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '#' && !vis[i][j]){
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';

    }

    return 0;
}
