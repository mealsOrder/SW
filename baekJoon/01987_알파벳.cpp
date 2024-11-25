#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MX = 21;

string map[MX];
int R,C;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int vis[MX][MX];
int alpha[26];
int mxDist;
int ans;

void DFS(int x,int y){
    char a = map[x][y];
    if(alpha[a - 65]) return;
    vis[x][y] = true;
    alpha[ a - 65] = true;
    mxDist++;

    ans = max(ans,mxDist);

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && nx<R && ny>=0 && ny<C && !vis[nx][ny]){
            DFS(nx,ny);
        }
    }
    alpha[a - 65] = false;
    mxDist--;
    vis[x][y] = false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R >> C;

    for(int i=0;i<R;i++){
        cin >> map[i];
    }

    DFS(0,0);
    cout << ans << '\n';
    return 0;
}