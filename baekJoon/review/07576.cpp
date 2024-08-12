#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

const int MX =  1001;
int M,N;
int map[MX][MX];
int dist[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ans;
queue<pair<int,int>>q;
void BFS(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M&&dist[nx][ny]==-1&&!map[nx][ny]){
                dist[nx][ny] = dist[x][y]+1;
                map[nx][ny]=1;
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
            cin >> map[i][j];
            if(map[i][j] == 1)q.push({i,j});
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dist[i][j] = -1;
        }
    }
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] == 0){
                cnt++;
            }
        }
    }
    if(cnt == 0){
        cout << "0\n";
        return 0;
    }
    BFS();

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ans = max(ans,dist[i][j]);
            if(map[i][j] == 0 && dist[i][j]==-1){
                cout << "-1\n";
                return 0;
            }
            //cout << map[i][j] << " ";
        }
        //cout << '\n';
    }
    cout << ans+1 << '\n';
    
    return  0;
}