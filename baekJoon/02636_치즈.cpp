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
bool vis[MX][MX];
int cheese;
int time;

void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            vis[i][j] = false;
        }
    }
}

void BFS(int x,int y){
    int cnt = 0;
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
            if(nx>=0 && nx<N && ny>=0 && ny<M && !vis[nx][ny]){
                if(map[nx][ny] == 1){
                    map[nx][ny] = 0;
                    vis[nx][ny] = true;
                    cnt++;
                }
                else{
                    q.push({nx,ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }
    cheese -= cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int pre = 0;
    cin >> N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j] == 1) cheese++;
        }
    }
    while(cheese>0){
        pre = cheese;
        init();
        BFS(0,0);
        time ++;
    }
    
    cout << time << '\n';
    cout << pre << '\n';
    return 0;
}