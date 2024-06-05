#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int MX = 606;
string map[MX];
bool vis[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int N,M;
int cnt;
queue<pair<int,int>>q;
void BFS(){
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx<0||nx>=N||ny<0||ny>=M)continue;
            if(map[nx][ny] == 'X')continue;
            if(vis[nx][ny])continue;
            if(map[nx][ny] == 'P') cnt ++;
            q.push({nx,ny});
            vis[nx][ny] = true;    
            
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >>N>>M;
    for(int i=0;i<N;i++){
        cin >> map[i];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] == 'I'){
                q.push({i,j});
            }
        }
    }
    BFS();
    if(cnt == 0) cout << "TT\n";
    else cout << cnt;
    return 0;
}
