#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MX = 101;
const int INF = 987987987;
int M,N;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
string map[MX];
int dist[MX][MX];
void BFS(){
    queue<pair<int,int>>q;
    dist[0][0] = 0;
    q.push({0,0});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0||nx>=N||ny<0||ny>=M)continue;
            if(map[nx][ny] == '0'){
                if(dist[nx][ny] > dist[x][y]){
                    dist[nx][ny] = dist[x][y];
                    q.push({nx,ny});
                }
            }
            else if(map[nx][ny] == '1') {
                if(dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // 가로, 세로
    cin >> M >> N;
    for(int i=0;i<N;i++){
        cin >> map[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dist[i][j] = INF;
        }
    }
    BFS();
    cout << dist[N-1][M-1] << '\n';
    return 0;
}