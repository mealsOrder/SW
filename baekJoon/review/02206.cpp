#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
const int MX = 1001;
const int INF = INT_MAX;
int map[MX][MX];
int dist[MX][MX][2];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int N,M,w;
queue< pair< pair<int,int>, int> >q;
int BFS(int x,int y){
    q.push({{x,y},0});
    dist[x][y][0] = 1;

    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int w = q.front().second;
        if(curX == N-1 && curY == M-1) return dist[curX][curY][w];
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M){
                if(map[nx][ny] == 0 && dist[nx][ny][w] == 0){
                    dist[nx][ny][w] = dist[curX][curY][w]+1;
                    q.push({{nx,ny},w});
                }
                else if(w==0 && map[nx][ny] ==1 && dist[nx][ny][1] == 0 ){
                    dist[nx][ny][1] = dist[curX][curY][0]+1;
                    q.push({{nx,ny},1});
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%1d",&map[i][j]);
        }
    }

    int ans = BFS(0,0);
    cout << ans << '\n';
   
    return 0;
}
