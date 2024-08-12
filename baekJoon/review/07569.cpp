#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 101;
int M,N,H;
int map[MX][MX][MX];
int dx[] = {0,0,0,0,1,-1}; 
int dy[] = {0,0,1,-1,0,0};
int dh[] = {1,-1,0,0,0,0,};
int ans;
queue<pair < int, pair<int,int> > >q;

void BFS(){
    while(!q.empty()){
        int h = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        for(int i=0;i<6;i++){
            int nh = h+dh[i];
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0||nx>=N||ny<0||ny>=M||nh<0||nh>=H)continue;
            if(map[nh][nx][ny]==-1)continue;
            if(map[nh][nx][ny]>=1)continue;
            map[nh][nx][ny] = map[h][x][y]+1;
            q.push({nh,{nx,ny}});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> M>>N>>H;

    for(int k=0;k<H;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin >> map[k][i][j];
                if(map[k][i][j] == 1){
                    q.push({k,{i,j}});
                }
            }
        }
    }
    BFS();
    for(int k=0;k<H;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[k][i][j] == 0){
                    cout << "-1\n";
                    return 0;
                }
                ans = max(ans,map[k][i][j]);
                // cout << map[k][i][j] << " ";
            }
            // cout << "\n";
        }
        // cout << "\n";
    }
    cout << ans-1 << '\n';
    return 0;
}