#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
const int MX = 33;

int L,R,C;
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> L>>R>>C;
        if(L == 0 && R == 0 && C == 0)break;
        queue<tuple<int,int,int>>q;
        char map[MX][MX][MX];
        int dist[MX][MX][MX];
        bool flag = false;
        for(int k=0;k<L;k++)
            for(int i=0;i<R;i++) fill(dist[k][i],dist[k][i]+C,0);

        for(int k=0;k<L;k++){
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    cin >> map[k][i][j];

                    if(map[k][i][j] == 'S'){
                        q.push({k,i,j});
                        dist[k][i][j] = 0;
                    }
                    else if(map[k][i][j] == '.'){
                        dist[k][i][j] = -1;
                    }
                }
            }
        }

        while(!q.empty()){
            if(flag) break;
            auto cur = q.front();
            q.pop();
            int curZ,curX,curY;
            tie(curZ,curX,curY) = cur;
            for(int i=0;i<6;i++){
                int nz = curZ+dz[i];
                int nx = curX+dx[i];
                int ny = curY+dy[i];

                if(nz<0||nz>=L||nx<0||nx>=R||ny<0||ny>=C)continue;
                if(dist[nz][nx][ny] >0 || map[nz][nx][ny] == '#') continue;
                dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
                if(map[nz][nx][ny] == 'E'){
                    cout << "Escaped in " << dist[nz][nx][ny] << " minute(s).\n";
                    flag = true;
                    break;
                }
                q.push({nz,nx,ny});
            }
        }
        while(!q.empty())q.pop();
        if(!flag) cout << "Trapped!" << '\n';
    }
    return 0;
}