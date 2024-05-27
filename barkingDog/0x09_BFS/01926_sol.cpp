#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 502;
int map[MX][MX];
int visited[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int N,M;
int cnt;
queue<pair<int,int>>q;

void BFS(int x,int y){
    if(visited[x][y])return;
    visited[x][y]=true;
    q.push({x,y});
    cnt++;
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M&&!visited[nx][ny]&&map[nx][ny]){
                visited[nx][ny] = true;
                q.push({nx,ny});
                cnt++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
    int mxCnt = 0;
    int number = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visited[i][j] && map[i][j]==1){
                cnt = 0;
                BFS(i,j);
                number++;
            }
            mxCnt = max(mxCnt,cnt);
        }
        
    }
    cout << number << "\n";
    cout << mxCnt << '\n';
	return 0;
}