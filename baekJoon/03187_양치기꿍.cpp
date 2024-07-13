#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 251;
string map[MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool vis[MX][MX];
int ans_v,ans_k;
int R,C;
queue<pair<int,int>>q;
void BFS(int x,int y){
    int v = 0, k = 0;

    vis[x][y]=true;
    q.push({x,y});
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        if(map[curX][curY] == 'v')v++;
        if(map[curX][curY] == 'k')k++;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<R&&ny>=0&&ny<C&&!vis[nx][ny]&&map[nx][ny]!='#'){
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    if(v>=k)ans_v+=v;
    else ans_k+=k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> R >>C;

    for(int i=0;i<R;i++){
        cin >> map[i];
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(!vis[i][j] && map[i][j] != '#') BFS(i,j);
        }
    }
    cout << ans_k << " " << ans_v << '\n';
    return 0;
}