#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 101;
int M,N;
string map[MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dist[MX][MX];
queue<pair<int,int>>q;
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dist[i][j] = -1;
        }
    }
}

void BFS(int x,int y){
    dist[x][y] = 0;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx<0||nx>=N||ny<0||ny>=M)continue;
            if(map[nx][ny] == '0')continue;
            if(dist[nx][ny] >=0)continue;
            
            dist[nx][ny] = dist[curX][curY]+1;
            q.push({nx,ny});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> M>>N;

    for(int i=0;i<N;i++){
        cin >> map[i];            
    }
    int ey,ex;
    cin >> ey >> ex;
    init();
    BFS(ex-1,ey-1);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(dist[i][j] >=0 ){
                dist[i][j] += 3;
            }
        }
    }
    int ans = 0;
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ans = max(ans,dist[i][j]);
            if(dist[i][j] < 3 && map[i][j] == '1')cnt ++;
            
        }
    }
    cout << ans <<'\n';
    cout << cnt ;
    return 0;
}