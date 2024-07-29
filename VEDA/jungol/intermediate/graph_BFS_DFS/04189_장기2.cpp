#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 1001;
int N,M;
int R,C,S,K;

int dx[] = {-2,-2,-1,1,2,2,1,-1};
int dy[] = {-1,1,2,2,1,-1,-2,-2};
int dist[MX][MX];
int ans;
queue<pair<int,int>>q;
void BFS(int x,int y){
    q.push({x,y});
    dist[x][y] = 0;

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();


        for(int i=0;i<8;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx<0||nx>=N||ny<0||ny>=M)continue;
            if(dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[curX][curY]+1;
            q.push({nx,ny});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    cin >> R >> C >> S >> K ;

    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            dist[i][j]= -1;
        }
    }   
    BFS(R-1,C-1);
    cout << dist[S-1][K-1] << '\n';
    return 0;
}