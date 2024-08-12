#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
const int MX = 1001;
int M,N;
int map[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ans = 0;

queue<pair<int,int>>q;

void BFS(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M&&map[nx][ny]==0){
                map[nx][ny] = map[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> M >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j] == 1)q.push({i,j});
        }
    }
    BFS();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] == 0){
                cout << "-1\n";
                return 0;
            }
            ans = max(ans,map[i][j]);
        }
    }
    cout << ans -1 << '\n';
    return 0;
}