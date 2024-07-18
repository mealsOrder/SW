#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 101;
int N,M;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int map[MX][MX];
int cloneM[MX][MX];
bool air_vis[MX][MX];
bool vis[MX][MX];

void air_BFS(int x, int y){
    queue<pair<int,int>>q;
    air_vis[x][y] = true;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0 && nx<N && ny>=0 && ny<M && !map[nx][ny] && !air_vis[nx][ny] ){
                air_vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
}

void BFS(int x,int y){
    queue<pair<int,int>>q;
    vis[x][y] = true;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();


        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && map[curX][curY] && air_vis[nx][ny] ){
                map[curX][curY] = 0;
                q.push({nx,ny});
            }
        }
    }

}
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cloneM[i][j] = map[i][j];
            air_vis[i][j] = false;
        }
    }
}
int cntCheese(){
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] == 1)cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
    int ans = 0;
    int res = 0;
    while(cntCheese() > 0){
        init();
        air_BFS(0,0);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j] && !vis[i][j]){
                    BFS(i,j);
                }
            }
        }
        ans++;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(cloneM[i][j] == 1)res++;
        }
    }
    
    cout << ans << '\n';
    cout << res << '\n';
    return 0;
}