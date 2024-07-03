#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<cmath>
using namespace std;
const int MX = 101;
// 문제를 보면 가로길이 N, 세로길이 M
// 정답률이 낮은 이유를 알겟따..
string map[MX];
bool vis[MX][MX];
int N,M;
int ans_w,ans_b;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};


void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            vis[i][j] = false;
        }
    }
}
void BFS(int x,int y,char s){
    int cnt = 1;
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y] = true;
    

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];
            
            if( nx>=0&&nx<M&&ny>=0&&ny<N && !vis[nx][ny] && map[nx][ny] == s){
                cnt++;
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    if(s == 'W') ans_w+= cnt*cnt;
    else ans_b += cnt*cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N>>M;

    for(int i=0;i<M;i++){
        cin >> map[i];
    }
    init();
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!vis[i][j]){
                BFS(i,j,map[i][j]);
            }
        }
    }

    cout << ans_w << " " << ans_b << '\n';

    return 0;
}