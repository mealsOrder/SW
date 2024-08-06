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
int dist[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ans = INF,res=INF;
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dist[i][j]= -1;
        }
    }
}
void func(int x,int y){
    queue<pair<int,int>>q;
    dist[x][y]=0;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M&&dist[nx][ny]<0){
                if(map[nx][ny] == 1)continue;
                dist[nx][ny]=dist[curX][curY]+1;
                q.push({nx,ny});
                if(map[nx][ny] == 2)ans = min(ans,dist[nx][ny]+(N-nx-1)+(M-ny-1));
            }
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
    func(0,0);

    if(dist[N-1][M-1] > -1){
        ans = min(ans,dist[N-1][M-1]);
    }

    if(ans>T)cout << "Fail\n";
    else cout << ans;
	return 0;
}