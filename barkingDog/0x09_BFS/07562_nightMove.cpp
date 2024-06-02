#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 303;
int N,si,sj,oi,oj;
int dist[MX][MX];
int dy[]={2,1,-1,-2,-2,-1, 1, 2};
int dx[]={1,2, 2, 1,-1,-2,-2,-1};
queue<pair<int,int>>q;

void BFS(int x,int y){
    dist[x][y] = 0;
    q.push({x,y});
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<8;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<N&&dist[nx][ny]<0){
                dist[nx][ny] = dist[curX][curY]+1;
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >>T;
    
    while(T--){
        cin >> N;
        for (int i = 0; i < N; i++) fill(dist[i], dist[i] + N, -1);

        cin >> si >> sj;
        cin >> oi >> oj;
        BFS(si,sj);
        cout << dist[oi][oj] << '\n';
    }
    
    return 0;
}