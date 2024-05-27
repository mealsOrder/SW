#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 1001;
int map[MX][MX];
int dist[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int N,M;
int ans;
queue<pair<int,int>>q;
void BFS(){
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&nx<N&&ny>=0&&ny<M&&dist[nx][ny] == -1){
                dist[nx][ny] = dist[curX][curY] + 1;
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    cin >> M >> N;
    //init();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                q.push({i,j});
            }
            if(map[i][j]==0){
                dist[i][j]=-1;
            }
        }
    }
    BFS();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(dist[i][j] == -1){
                cout << "-1\n" ;
                return 0;
            }
            ans = max(ans,dist[i][j]);
        }
    }
    cout << ans<< '\n';
	return 0;
}