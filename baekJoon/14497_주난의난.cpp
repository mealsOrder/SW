#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 301;
int N,M,ans;
bool flag = false;
string map[MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int a,b,c,d;
bool vis[MX][MX];
void init(){
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            vis[i][j] = false;
        }
    }
}
void BFS(int x,int y){
    queue<pair<int,int>>q;
    init();
    q.push({x,y});
    vis[x][y] = true;
    
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx<0||nx>=N||ny<0||ny>=M)continue;
            if(vis[nx][ny] == true ) continue;
            if(map[nx][ny] == '1') map[nx][ny] = '0';
            else if(map[nx][ny] == '0')q.push({nx,ny});
            else flag = true;
            vis[nx][ny] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N>>M;
    cin >> a>>b>>c>>d;

    for(int i=0;i<N;i++){
        cin >> map[i];
    }
    a--;
    b--;
    while(!flag){
        BFS(a,b);
        ans++;
    }
    cout << ans << '\n';
    
    return 0;
}