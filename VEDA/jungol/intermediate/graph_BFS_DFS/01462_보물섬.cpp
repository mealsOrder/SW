#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MX = 51;

int N,M;
string map[MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dist[MX][MX];
int ans;
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dist[i][j] = -1;
        }
    }
}
void BFS(int x,int y){
    queue<pair<int,int>>q;
    
    dist[x][y] = 0;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx<0||nx>=N&&ny<0||ny>=M)continue;
            if(map[nx][ny] == 'W')continue;
            if(dist[nx][ny]>=0)continue;

            dist[nx][ny] = dist[curX][curY]+1;
            q.push({nx,ny});
            ans = max(ans,dist[nx][ny]);
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        cin >> map[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] == 'L'){
                init();
                BFS(i,j);
            }
        }
    }
    cout << ans << '\n';
	return 0;
}