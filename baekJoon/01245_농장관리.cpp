#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MX = 101;
int n,m;
int board[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int cnt;
bool vis[MX][MX];

queue<pair<int,int>>q;

void bfs(int x,int y){
    if(board[x][y]){
        vis[x][y]=1;
        q.push({x,y});
    }

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny] !=0 && !vis[nx][ny] ){
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    cnt++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	
	cin >> n >> m;

	for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }

    bfs(0,0);


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(!vis[i][j] && board[i][j] != 0)bfs(i,j);
        }
    }

    cout << cnt << '\n';
    return 0;
}