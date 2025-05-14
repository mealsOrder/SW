#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<cstring>
using namespace std;

const int MX = 101;

int N,ans=987987987,cnt=1;
int map[MX][MX];
int clo[MX][MX];
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
bool vis[MX][MX];


void BFS1(int x,int y){
    queue<pair<int,int>>q;
    vis[x][y]=true;
    clo[x][y]=cnt;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<N&&map[nx][ny]&&!vis[nx][ny]){
                clo[nx][ny] = cnt;
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    cnt++;
}

int BFS2(int id){
    queue<pair<int,int>>q;
    int dist[MX][MX];
    memset(dist,-1,sizeof(dist));

    // 시작 섬의 모든 경계지점 넣기!!!! ******
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(clo[i][j] == id){
                q.push({i,j});
                dist[i][j]=0;
            }
        }
    }

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];
            
            // 유효 범위에 있고
            if(nx>=0&&nx<N&&ny>=0&&ny<N){
                
                // 바다라면 거리 추가
                if(clo[nx][ny] == 0 && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[curX][curY]+1;
                    q.push({nx,ny});
                }

                // 다른 섬이라면 거리 반환
                else if(clo[nx][ny] != 0 && clo[nx][ny] != id){
                    return dist[curX][curY];
                }
            }

        }
    }
    return 987987987;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!vis[i][j] && map[i][j]){
                BFS1(i,j);
            }
        }
    }
    int res = 987987987;

    for(int i=1;i<=cnt;i++){
        res = min(res,BFS2(i));
    }
    cout << res << '\n';
    return 0;
}
