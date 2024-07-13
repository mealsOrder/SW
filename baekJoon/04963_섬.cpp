#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 51;
int map[MX][MX];
bool vis[MX][MX];
int W,H; // 너비 높이
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int ans;

void init(){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            map[i][j] = 0;
            vis[i][j] = false;
        }
    }
}
void BFS(int x,int y){
    queue<pair<int,int>>q;
    vis[x][y]=true;
    q.push({x,y});
    
    
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        
        q.pop();

        for(int i=0;i<8;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<H&&ny>=0&&ny<W&&!vis[nx][ny]&&map[nx][ny]){
                vis[nx][ny]=true;
                q.push({nx,ny});
                
            }
        }
    }
    ans++;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    while(true){
        ans = 0;
        cin >> W>>H;
        init();
        if(W == 0 && H == 0) break;

        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cin >> map[i][j];
            }
        }

        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(map[i][j] && !vis[i][j]){
                    BFS(i,j);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}