#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
using namespace std;

const int MX = 202;
int dist[MX][MX];
int N;
int r1,c1,r2,c2;
int dx[] = {-2,-2,0,0,2,2};
int dy[] = {-1,1,-2,2,-1,1};
queue<pair<int,int>>q;
int BFS(int x,int y){

    dist[x][y] = 1;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;

        if(curX == r2 && curY == c2) return dist[curX][curY]-1;
        q.pop();

        for(int i=0;i<6;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<N&&!dist[nx][ny]){
                dist[nx][ny] = dist[curX][curY]+1;
                q.push({nx,ny});
            }
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    cin >> r1 >> c1 >> r2 >> c2;

    int ans = BFS(r1,c1);
    cout << ans << '\n';
    return 0;
}