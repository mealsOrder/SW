#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;
const int MX = 51;
const int INF = 987987987;
int N;
string map[MX];
int dist[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
typedef tuple<int,int,int> t;
void init(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dist[i][j]=INF;
}
void dijkstra(int x,int y){
    priority_queue< t,vector<t>,greater<t>>pq;// cost,x,y
    pq.push({0,x,y});
    dist[x][y] = 0;

    while(!pq.empty()){
        int cost,curX,curY;
        tie(cost,curX,curY) = pq.top();
        pq.pop();
        if(dist[curX][curY] < cost)continue;

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx<0||nx>=N||ny<0||ny>=N)continue;
            int nxCost = cost + (map[nx][ny] == '0'?1:0);

            if(dist[nx][ny] > nxCost){
                dist[nx][ny] = nxCost;
                pq.push({nxCost,nx,ny});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);

    cin >> N;
    for(int i=0;i<N;i++) cin >> map[i];

    init();
    dijkstra(0,0);
    cout << dist[N-1][N-1];
    return 0;
}