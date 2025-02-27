#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MX = 1001;
int N,M;
int map[MX][MX];
bool vis[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

queue<pair<int,int>>q;

void BFS(){
    

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;    
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0&&nx<M&&ny>=0&&ny<N&& !vis[nx][ny] &&!map[nx][ny]){
                map[nx][ny] = map[x][y]+1;
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}

int cal(){
    int mxn = 0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(map[i][j] == 0){
                return -1;
            }
            else{
                if ( map[i][j] > mxn){
                    mxn = map[i][j];
                }
            }
            
        }
    }
    return mxn-1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
    }

    BFS();
    cout << cal() << '\n';
    return 0;
}