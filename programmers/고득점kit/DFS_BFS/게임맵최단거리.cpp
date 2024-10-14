#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MX = 101;
int dist[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};


int BFS(int x,int y,vector<vector<int> > maps){
    queue<pair<int,int>>q;
    int N = maps.size();
    int M = maps[0].size();

    dist[x][y] = 1;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        if(curX == N-1 && curY == M-1) return dist[N-1][M-1];
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M&&maps[nx][ny]&&!dist[nx][ny]){
                dist[nx][ny] = dist[curX][curY]+1;
                q.push({nx,ny});
            }
        }
    }
    return -1;
}
int solution(vector<vector<int> > maps)
{   
    int ans = BFS(0,0,maps);
    

    return ans;
}
int main(){



    return 0;
}