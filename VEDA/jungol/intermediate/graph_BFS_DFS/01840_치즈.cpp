#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MX = 101;
int N,M;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int map[MX][MX];
bool vis[MX][MX];
int cheese;
int ans;
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            vis[i][j] = false;
        }
    }
}

void BFS(){
    queue<pair<int,int>>q;
    int cnt = 0;
    vis[0][0] = true;
    q.push({0,0});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 && nx<N && ny>=0 && ny<M && !vis[nx][ny]){
                if(map[nx][ny] == 1){
                    vis[nx][ny] = true;
                    map[nx][ny] = 0;
                    cnt++;
                }
                else{
                    vis[nx][ny] = true;
                    q.push({nx,ny});
                }
            }

        }

    }
    cheese -= cnt;
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int pre = 0;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                cheese++;
            }
        }
    }

    while(cheese > 0){
        pre = cheese;
        init();
        BFS();
        ans++;
    }
    cout << ans << '\n';
    cout << pre;

	return 0;
}