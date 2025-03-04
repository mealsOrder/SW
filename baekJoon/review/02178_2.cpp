#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int MX = 101;

string map[MX];
int vis[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int N,M,ans;

queue<pair<int,int>>q;
void BFS(int x,int y){
    vis[x][y] = 1;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        if(curX == N-1 && curY == M-1)return;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M&&vis[nx][ny] == -1 &&map[nx][ny] != '0'){
                vis[nx][ny]= vis[curX][curY]+1;
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        cin >> map[i];
    }
    memset(vis,-1,sizeof(vis));
    BFS(0,0);
    cout << vis[N-1][M-1];
    return 0;
}