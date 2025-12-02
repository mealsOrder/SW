#include <bits/stdc++.h>
using namespace std;

const int MX = 251;
int n,m;
bool board[MX][MX];
bool vis[MX][MX];

// 8방향
int dx[] = {-1,-1,-1, 0,0, 1,1,1};
int dy[] = {-1, 0, 1,-1,1,-1,0,1};


void bfs(int x,int y){
    queue<pair<int,int>>q;
    vis[x][y] = true;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<8;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx<0||nx>=n||ny<0||ny>=m)continue;

            if(board[nx][ny] && !vis[nx][ny]){
                vis[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0;
    for (int i=0;i<n;i++) {
        for (int j= 0; j<m;j++) {
            if (!vis[i][j] && board[i][j] == 1) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    
    cout << cnt << '\n';
    return 0;
}
