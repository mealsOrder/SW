#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
const int MX = 1001;

string board[MX];
int dist1[MX][MX];
int dist2[MX][MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
queue<pair<int,int>>q1;
queue<pair<int,int>>q2;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int R,C;
    cin >> R>>C;
    for(int i=0;i<R;i++){
        fill(dist1[i],dist1[i]+C,-1);
        fill(dist2[i],dist2[i]+C,-1);
    }
    for(int i=0;i<R;i++){
        cin>>board[i];
    }
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(board[i][j] == 'F'){
                q1.push({i,j});
                dist1[i][j]=0;
            }
            if(board[i][j] == 'J'){
                q2.push({i,j});
                dist2[i][j]=0;
            }
        }
    }
    while(!q1.empty()){
        int curX = q1.front().first;
        int curY = q1.front().second;
        q1.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx<0||nx>=R||ny<0||ny>=C)continue;
            if(dist1[nx][ny]>=0||board[nx][ny] == '#')continue;
            dist1[nx][ny] = dist1[curX][curY]+1;
            q1.push({nx,ny});
        }

    }

    while(!q2.empty()){
        int curX = q2.front().first;
        int curY = q2.front().second;
        q2.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            // 탈출 조건
            if(nx<0||nx>=R||ny<0||ny>=C){
                cout << dist2[curX][curY]+1;
                return 0;
            }
            if(dist2[nx][ny]>=0 || board[nx][ny] == '#')continue;

            /**
             * 첫 번째 조건 dist1[nx][ny]!=-1은 불이 해당 위치에 도달했는지를 확인합니다. 
             * -1은 불이 아직 도달하지 않은 위치를 나타냅니다. 
             * 따라서 dist1[nx][ny]!=-1은 불이 해당 위치에 도달했음을 의미합니다.
             * 두 번째 조건 dist1[nx][ny] <= dist2[curX][curY]+1은 
             * 불이 도달하는 시간이 지훈이가 도달하는 시간보다 빠른지를 확인합니다. 
             * dist1[nx][ny]는 불이 해당 위치에 도달하는 시간을, 
             * dist2[curX][curY]+1은 지훈이가 해당 위치에 도달하는 시간을 나타냅니다. 
             * 따라서 dist1[nx][ny] <= dist2[curX][curY]+1은 불이 지훈이보다 먼저 해당 위치에 도달함을 의미합니다.
             * +++
             * dist1[nx][ny] <= dist2[curX][curY]+1 대신
             * dist1[nx][ny] <= dist2[nx][ny] 조건을 사용하면 될것 같고 맞을것 같지만
             * 지훈이가 이미 그 위치에 도달한 시간을 고려하게 됩니다. 
             * 이는 지훈이가 다음 위치로 이동하려고 할 때의 시간과는 다를 수 있습니다
            */
            if(dist1[nx][ny]!=-1 && dist1[nx][ny] <= dist2[curX][curY]+1)continue;

            dist2[nx][ny] = dist2[curX][curY]+1;
            q2.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}