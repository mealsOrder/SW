#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int MX = 1501;

bool map[MX][MX];
int R,C,day,sx,sy,ex,ey;
bool vis[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<pair<int,int>>l;
bool bfs(int x,int y){
    queue<pair<int,int>>q;
    memset(vis,0,sizeof(vis));
    q.push({x,y});
    vis[x][y]=true;

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        if(curX == ex && curY == ey) return 1;

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<R&&ny>=0&&ny<C&&!vis[nx][ny]&&map[nx][ny]==0){
                q.push({nx,ny});
                vis[nx][ny]=true;
            }
        }
    }
    return 0;
}

void melt(){
    vector<pair<int, int>>k;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j] == 1){
                for(int d=0;d<4;d++){
                    int ni = i+dx[d];
                    int nj = j+dy[d];
                    if(ni>=0&&ni<R&&nj>=0&&nj<C&&map[ni][nj]==0){
                        k.push_back({i,j});
                        break;
                    }
                }
                
            }
        }
    }
    for (int t=0;t<k.size();t++){
        int x = k[t].first;
        int y = k[t].second;
        map[x][y] = 0; // 얼음 → 물
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R >> C;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            char a;
            cin >> a;
            if(a == '.') map[i][j] = 0;
            else if(a == 'L'){
                l.push_back({i,j});
                map[i][j] = 0;
            }
            else map[i][j] = 1;
        }
    }
    sx = l[0].first; sy = l[0].second;
    ex = l[1].first; ey = l[1].second;
    while(1){
        int ok = bfs(sx,sy);
        if(ok) break;
        else{
            melt();
        }
        day++;
        
    }

    cout << day << '\n';
    return 0;
}