#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;
const int MX = 21;
int R,C;
string map[MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int ans,cnt;
bool vis[MX][MX];
bool alpha[26];

void DFS(int x,int y){
    char a = map[x][y];
    if(alpha[a - 65]) return;
    alpha[a - 65] = true;
    vis[x][y] = true;
    cnt++;

    ans = max(ans,cnt);
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0&&nx<R&&ny>=0&&ny<C&&!alpha[ map[nx][ny] - 65] && !vis[nx][ny]){
            DFS(nx,ny);
        }
    }
    cnt--;
    alpha[a - 65] = false;
    vis[x][y] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> R >> C;

    for(int i=0;i<R;i++){
        cin >> map[i];
    }

    DFS(0,0);

    cout << ans << '\n';

    return 0;
}