#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int MX = 101;
int N,cnt;
int map[MX][MX];
int dis[MX][MX];
bool vis[MX][MX];
bool chk[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<int>ans;

void BFS(int x,int y){
    queue<pair<int,int>>q;
    if(vis[x][y])return;
    vis[x][y] = true;
    q.push({x,y});
    cnt++;
    dis[x][y]=cnt;
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<N&&!vis[nx][ny]&&map[nx][ny]){
                vis[nx][ny]=true;
                dis[nx][ny]=cnt;
                q.push({nx,ny});
            }
        }
    }
}

void func(int x,int y,int val){
    queue<pair<int,int>>q;

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

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j] == 1){
                BFS(i,j);
            }
        }
    }
    cout << '\n';
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << dis[i][j] << " ";
        }
        cout << '\n';
    }
    
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(dis[i][j]){
                func(i,j,dis[i][j]);
            }
        }
        
    }
    return 0;
}