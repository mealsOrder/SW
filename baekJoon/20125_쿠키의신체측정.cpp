#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MX = 1001;
string map[MX];
bool vis[MX][MX];
int N;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int ans;
int sx,sy;
bool flag;
void DFS(int x,int y,int dir,int& cnt){
    if(vis[x][y]) return;
    vis[x][y] = true;

    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx>=0&&nx<N&&ny>=0&&ny<N &&!vis[nx][ny] && map[nx][ny] == '*'){
        cnt++;
        DFS(nx,ny,dir,cnt);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> map[i];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j] == '*'){
                vis[i][j] = true;
                sx = i+1;
                sy = j;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    cout << sx+1 << " " << sy+1 << '\n';
    for(int i=0;i<3;i++){
        ans = 0;
        vis[sx][sy]=false;
        DFS(sx,sy,i,ans);
        cout << ans << " ";
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!vis[i][j] && map[i][j] == '*'){
                ans = 1;
                DFS(i,j,2,ans);
                cout << ans << " ";
            }
        }
    }
    return 0;
}
