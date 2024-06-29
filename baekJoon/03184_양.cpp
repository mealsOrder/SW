#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<deque>
using namespace std;
const int MX = 251;
string map[MX];
bool vis[MX][MX];
int R,C;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ans_o,ans_v;
void BFS(int x,int y){
    queue<pair<int,int>>q;
    int v=0,o=0;
    vis[x][y]=true;
    q.push({x,y});
    if(map[x][y] == 'v')v++;
    else if(map[x][y] == 'o')o++;

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<R&&ny>=0&&ny<C&&!vis[nx][ny]&&map[nx][ny]!='#'){
                vis[nx][ny] = true;
                q.push({ nx, ny });
                if (map[nx][ny] == 'v') v++;
                else if (map[nx][ny] == 'o') o++;
            }
        }
    }
    if (o > v) ans_o += o;
    else ans_v += v;
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
            if(map[i][j]!='#' && !vis[i][j]){
                BFS(i,j);
            }
        }
    }
    cout << ans_o << " " << ans_v;    
    return 0;
}