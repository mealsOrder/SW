#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<deque>
using namespace std;
const int MX = 6;
string map[MX];
bool vis[MX][MX];
int R,C,K;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ans;
void DFS(int x,int y,int cnt){
    vis[x][y] = true;
    if(x == 0 && y == C-1){
        if(cnt == K) ans++;
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0&&nx<R&&ny>=0&&ny<C&&map[nx][ny]!='T'&&!vis[nx][ny]){
            vis[nx][ny] = true;
            DFS(nx,ny,cnt+1);
            vis[nx][ny] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R>>C>>K;

    for(int i=0;i<R;i++){
        cin >> map[i];
    }

    DFS(R-1,0,1);

    cout << ans<<'\n';

    return 0;
}