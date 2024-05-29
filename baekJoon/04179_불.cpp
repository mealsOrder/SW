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
            if(dist1[nx][ny]!=-1 && dist1[nx][ny] <= dist2[curX][curY]+1)continue;
            dist2[nx][ny] = dist2[curX][curY]+1;
            q2.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}