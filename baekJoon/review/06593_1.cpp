#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 31;
int L,R,C,ans;
bool flag = false;
char map[MX][MX][MX];
int dist[MX][MX][MX];
int dz[]={1,-1,0,0,0,0};
int dx[]={0,0,1,-1,0,0};
int dy[]={0,0,0,0,1,-1};
queue<pair<int,pair<int,int>>>q;

void BFS(){
    while(!q.empty()){
        int curZ = q.front().first;
        int curX = q.front().second.first;
        int curY = q.front().second.second;
        q.pop();

        for(int i=0;i<6;i++){
            int nz = curZ+dz[i];
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nz<0||nz>=L||nx<0||nx>=R||ny<0||ny>=C)continue;
            if(map[nz][nx][ny] == '#')continue;
            if(dist[nz][nx][ny] >=0)continue;
            dist[nz][nx][ny] = dist[curZ][curX][curY]+1;
            if(map[nz][nx][ny] == 'E'){
                flag = true;
                ans = dist[curZ][curX][curY];
            }
            q.push({nz,{nx,ny}});
        }

    }
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    while(1){
        cin >> L>>R>>C;
        if(L==0&&R==0&&C==0) break;
        for(int k=0;k<L;k++){
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    cin >> map[k][i][j];
                    if(map[k][i][j] == 'S'){
                        q.push({k,{i,j}});
                        dist[k][i][j] = 0;
                    }
                    if(map[k][i][j] == '.'){
                        dist[k][i][j] = -1;
                    }
                    
                }
            }
        }
        flag = false;
        BFS();
        if(!flag){
            cout << "Trapped!" << '\n';
        }
        else{
            cout <<  "Escaped in "<< ans <<" minute(s)." << '\n';
        }
    }

	return 0;
}
