#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MX = 1003;

int map[MX][MX];
bool vis[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int M,N,ans,cnt;
queue<pair<int,int>>q;

void BFS(){
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        vis[x][y] = true;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M&&!vis[nx][ny]&&map[nx][ny]==0){
                q.push({nx,ny});
                vis[nx][ny] = true;
                map[nx][ny] = map[x][y]+1;
                ans = max(ans,map[nx][ny]);
            }

        }
        
    }
}

int cal(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] == 0){
                return -1;
            }
        }
    }
    if(ans -1 < 0) return 0;
    else return ans -1; 
}

int main(){

    cin >> M >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                q.push({i,j});
                vis[i][j] = true;
                cnt++;
            }
        }
    }

    BFS();

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << cal() << '\n';
    return 0;
}