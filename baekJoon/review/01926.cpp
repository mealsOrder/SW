#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MX = 502;
int N,M,cnt,ans;
int map[MX][MX];
bool vis[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
vector<int>v;


void BFS(int x, int y){
    queue<pair<int,int>>q;
    vis[x][y] = 1;
    q.push({x,y});
    int cnt = 1;
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<M&&!vis[nx][ny]&&map[nx][ny]){
                vis[nx][ny]=1;
                q.push({nx,ny});
                cnt++;
            }
        }
    }
    v.push_back(cnt);
    ans++;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }

 
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] && !vis[i][j]){
                cnt = 0;
                BFS(i,j);
            }
        }
    }
    
    sort(v.begin(),v.end(),greater<>());
    cout << v.size() << '\n';
    if(!v.empty())cout << v[0] << '\n';
    else cout << 0 <<'\n';
    
    
    return 0;
}