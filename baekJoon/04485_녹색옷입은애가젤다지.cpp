#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 126;
const int INF = INT_MAX;
int N;
int map[MX][MX];
int dist[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dist[i][j] = INF;
        }
    }   
}
void BFS(int x,int y){
    queue<pair<int,int>>q;
    init();
    dist[x][y] = map[x][y]; // 첫거리가 0 아닌거에 주의!
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx<0||nx>=N||ny<0||ny>=N)continue;
            if(dist[nx][ny] <= dist[curX][curY] + map[nx][ny])continue;

            dist[nx][ny] = dist[curX][curY] + map[nx][ny];
            q.push({nx,ny});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k = 1;
    while(true){
        cin >> N;
        if(N==0) return 0;

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> map[i][j];
            }
        }
        BFS(0,0);
        cout << "Problem " << k << ": " << dist[N-1][N-1] << '\n';
        k++;
    }
    return 0;
}