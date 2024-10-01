#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 501;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool vis[MX][MX];
bool landVis[MX][MX];


int solution(vector<vector<int>> land) {
    int ans=0;
    int sum=0;
    int cnt=0;
    int N = land.size();
    int M = land[0].size();
    for(int i=0;i<N; i++){
        sum=0;
        for(int j=0;j<M; j++){
            if(land[i][j] && !landVis[i][j]){
                cnt = 0;
                queue<pair<int,int>>q;
                q.push({i,j});
                vis[i][j] = true;

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int d=0;d<4;d++){
                        int nx = x+dx[d];
                        int ny = y+dy[d];

                        if(nx<0||nx>=N||ny<0||ny>=M) continue;
                        if(!vis[nx][ny]&&land[nx][ny]){
                            q.push(nx,ny);
                            cnt++;
                        }

                    }
                }
            }
        }
        sum+=cnt;
        ans = max(ans,sum);
    }

    return ans;
}


int main(){
    
	return 0;
}