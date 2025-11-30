#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
using namespace std;

/**
 * @brief [01996]지뢰찾기
 * 이 문제는 굳이 BFS를 사용할 필요가 없는 문제
 * 
 *  
 */

const int MX = 1001;
char map[MX][MX];
int dp[MX][MX];

int N;
int dx[] = {-1,0,  1 ,-1, 1,-1,0,1};
int dy[] = {-1,-1,-1 , 0, 0, 1,1,1};


queue<pair<int,int>>q;
vector<pair<int,int>>v;
void BFS(){
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<8;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];
            
            if(nx>=0&&nx<N&&ny>=0&&ny<N&&map[nx][ny] == '.'){
                if(!dp[nx][ny]){
                    dp[nx][ny] = dp[curX][curY];
                }
                else{
                    dp[nx][ny] += dp[curX][curY];
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j] != '.'){
                q.push({i,j});
                dp[i][j] = map[i][j] - '0';
                v.push_back({i,j});
            }
        }
    }

    BFS();

    for(auto e:v) dp[e.first][e.second] = -1;
    

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(dp[i][j] == -1) cout << '*';
            else if(dp[i][j]>=10) cout << 'M';
            else cout << dp[i][j];
        }
        cout << '\n';
    }
    return 0;
}
