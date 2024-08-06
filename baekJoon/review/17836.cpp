#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 101;
const int INF = INT_MAX;
int N,M,T;
int map[MX][MX];
int dist[MX][MX][2];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }
}

void func(int x,int y,int w){
    queue<pair<pair<int,int>,int>>q;
    dist[x][y][w]=0;
    q.push({{x,y},w});

    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int curW = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];
            if(nx<0||nx>=N||ny<0||ny>=M)continue;
            if(dist[nx][ny][curW] != -1)continue;
            if(curW == 0 && map[nx][ny]==1)continue;

            int nw = (map[nx][ny] == 2)?1:curW;

            dist[nx][ny][nw] = dist[curX][curY][curW]+1;
            q.push({{nx,ny},nw});
        }

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> M >>T;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }
    init();
    func(0,0,0);
    int a1 = (dist[N-1][M-1][0] == -1)?INF:dist[N-1][M-1][0];
    int a2 = (dist[N-1][M-1][1] == -1)?INF:dist[N-1][M-1][1];
    int ans = min(a1,a2);
    if(ans>T)cout << "Fail\n";
    else cout << ans;
	return 0;
}