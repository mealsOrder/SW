#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 101;
int map[MX][MX];
int dist[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int N,M;
int cnt;
queue<pair<int,int>>q;
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dist[i][j]=-1;
        }
    }
}
int BFS(int x,int y){
    dist[x][y] = 1;
    q.push({x,y});
    

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        if(curX == N-1 && curY == M-1) return dist[N-1][M-1];
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M&& dist[nx][ny]== -1 &&map[nx][ny]){
                dist[nx][ny]=dist[curX][curY]+1;
                q.push({nx,ny});
            }
        }
    }

    return -1;
}

int main(){
    cin >> N>>M;
    init();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%1d",&map[i][j]);
        }
    }

    int ans = BFS(0,0);

    
    cout << ans;

	return 0;
}