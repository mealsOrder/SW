#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int MX = 301;

int N,M,land,year;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool vis[MX][MX];
int map[MX][MX];

void BFS(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=true;

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];
            // 유효 범위이면서서
            if(nx>=0&&nx<N&&ny>=0&&ny<M&&!vis[nx][ny]&&map[nx][ny]>0){
                q.push({nx,ny});
                vis[nx][ny]=true;
            }
        }
    }
    land++; // 섬갯수 증가
}

void melt(){
    int clo[MX][MX] = {0,};

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]>0){
                int cnt = 0; // 바다 칸 수
                for(int d=0;d<4;d++){
                    int ni = i+dx[d];
                    int nj = j+dy[d];

                    if(ni>=0&&ni<N&&nj>=0&&nj<M && map[ni][nj] == 0){
                        cnt++;
                    }
                }
                clo[i][j] = max(0,map[i][j] - cnt);
            }
        }
    }
    memcpy(map,clo,sizeof(map));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }

    while(1){
        land = 0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]>0 && !vis[i][j]){
                    BFS(i,j);
                }
            }
        }
        if(land>=2)break;
        if(land == 0){
            year = 0;
            break;
        }
        melt();
        year++;
    }
    
    cout << year << '\n';
    return 0;
}