#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
const int MX = 101;
/**
 * 3차워원 배열 루프 순서
 * int arr[H][N][M]
 *    arr[높이(깊이)][가로][세로]
 * for(int k=0;k<H;k++)
 *      for(int i=0;i<N;i++)
 *          for(int j=0;j<M;j++)
 * 예시 백준 7569 토마토 문제
 */
int map[MX][MX][MX];
int dx[] = {0,0,1,-1,0,0};
int dy[] = {1,-1,0,0,0,0};
int dz[] = {0,0,0,0,1,-1};
int dist[MX][MX][MX];
using namespace std;
int M,N,H;
queue<pair<pair<int,int>,int >>q;
void DFS(){
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();

        for(int i=0;i<6;i++){
            int nx = x+dx[i]; 
            int ny = y+dy[i];
            int nz = z+dz[i];

            if(nx<0||nx>=N||ny<0||ny>=M||nz<0||nz>=H)continue;
            if(dist[nx][ny][nz]>=0)continue;
            dist[nx][ny][nz] = dist[x][y][z]+1;
            q.push({{nx,ny},nz});
        }
        
    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M>>N>>H;

    for(int k=0;k<H;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin >> map[i][j][k];
                
                if(map[i][j][k] == 1) {
                    q.push({{i,j},k});
                    dist[i][j][k] = 0;
                }
                if(map[i][j][k] == 0) {
                    dist[i][j][k] = -1;
                }
            }
        }
    }
    int ans = 0;
    DFS();
    for(int k=0;k<H;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(dist[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
                ans = max(ans,dist[i][j][k]);
            }
        }
    }
    cout << ans;
    return 0;
}
