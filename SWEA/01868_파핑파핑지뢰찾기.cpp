#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MX = 303;
string map[MX];
int dx[] = {-1,-1,-1,0,1,1, 1, 0};
int dy[] = {-1, 0, 1,1,1,0,-1,-1};
bool vis[MX][MX];
int num[MX][MX];
int ans,N;

void BFS(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y] = true;
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<8;i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<N&&!vis[nx][ny]){
                vis[nx][ny] = true;
                if(num[nx][ny] == 0){
                    q.push({nx,ny});
                }
                
            }
        }
    }
}

void BFS_BOOM(vector<string>map){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j] == '*') vis[i][j] = true;
            else{
                int cnt = 0;
                for(int k=0;k<8;k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];

                    if(nx>=0&&nx<N&&ny>=0&&ny<N && map[nx][ny] == '*'){
                        cnt++;
                    }
                }

                num[i][j] = cnt;
            }
        }
    }
}
int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	
    int T;
    cin >> T;

    for(int t=1;t<=T;t++){
        int ans = 0;
        cin >> N;
        vector<string>map(N);
        for(int i=0;i<N;i++){
            cin >> map[i];
        }
        memset(vis,false,sizeof(vis));

        BFS_BOOM(map);

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!vis[i][j] && num[i][j] == 0){
                    ans ++;
                    BFS(i,j);
                }
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!vis[i][j]){
                    ans++;
                }
            }
        }

        cout << '#' << t << ' ' << ans << '\n';
    }
		
	

    return 0;
}