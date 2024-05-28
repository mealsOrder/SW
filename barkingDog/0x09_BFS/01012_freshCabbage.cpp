#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
const int MX = 51;
int map[MX][MX];
bool visited[MX][MX];
int M,N,K;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
queue<pair<int,int>>q;
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            map[i][j] = 0;
            visited[i][j] = false;
        }
    }
}
void BFS(int x, int y){
    visited[x][y] = true;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M&&map[nx][ny]&&!visited[nx][ny]){
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin >> M>>N>>K;
        init();
        int cnt = 0;
        for(int i=0;i<K;i++){
            int a, b;
            cin >> a >> b;

            map[b][a] = 1;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!visited[i][j] && map[i][j]){
                    BFS(i,j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }
    return 0;
}