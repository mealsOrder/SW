#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 1001;
string map[MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool vis[MX][MX];
int M,N;
// 0전류, 1노전류
bool BFS(int x,int y){
    queue<pair<int,int>>q;
    vis[x][y] = true;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        if(curX == M-1) return true;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[nx][ny]=='0'&&!vis[nx][ny]){
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> M>>N;

    for(int i=0;i<M;i++){
        cin >> map[i];
    }
    bool ans = false;
    for(int i=0;i<N;i++){
        if(map[0][i]=='0' && !vis[0][i]){
            ans = BFS(0,i);
            if(ans) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    
    return 0;
}