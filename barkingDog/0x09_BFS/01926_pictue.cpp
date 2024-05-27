#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int mxCnt = 502;
int map[mxCnt][mxCnt];
int visited[mxCnt][mxCnt];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int N,M;
int cnt;
queue<pair<int,int>>q;
vector<int>v;
void BFS(int x,int y){
    if(visited[x][y]) return;
    q.push({x,y});
    visited[x][y]=true;
    cnt++;
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>0&&nx<=N&&ny>0&&ny<=M&&!visited[nx][ny]&&map[nx][ny]){
                BFS(nx,ny);
            }
        }
    }


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N>>M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> map[i][j];
        }
    }
    int mxCnt=0; // 그림 최대값
    int number=0; // 그림의 수
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(!visited[i][j] && map[i][j] == 1){
                cnt = 0;
                BFS(i,j);
                number++;
                mxCnt = max(mxCnt,cnt);
            }
        }
    }
    
    cout << number << '\n';
    cout << mxCnt;
	return 0;
}