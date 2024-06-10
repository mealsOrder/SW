#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 33;

int L,R,C;
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
int ek,ei,ej;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> L>>R>>C;
        if(L == 0 && R == 0 && C == 0)break;
        queue<pair<int,pair<int,int>>>q;
        char map[MX][MX][MX];
        int dist[MX][MX][MX];
        bool flag = false;
        int ans = 0;
        for(int k=0;k<L;k++)
            for(int i=0;i<R;i++) fill(dist[k][i],dist[k][i]+C,0);

        for(int k=0;k<L;k++){
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    cin >> map[k][i][j];

                    if(map[k][i][j] == 'S'){
                        q.push({k,{i,j}});
                        dist[k][i][j] = 0;
                    }
                    if(map[k][i][j] == 'E'){
                        ek=k;ei=i;ej=j;
                        dist[k][i][j] = -1;
                    }
                    if(map[k][i][j] == '.'){
                        dist[k][i][j] = -1;
                    }
                }
            }
        }

        while(!q.empty()){
            if(flag) break;
            int curZ = q.front().first;
            int curX = q.front().second.first;
            int curY = q.front().second.second;
            q.pop();
            if(curZ == ek && curX == ei && curY == ej ){
                ans =  dist[curZ][curX][curY];
                flag = true;
                break;
            }
            for(int i=0;i<6;i++){
                int nz = curZ+dz[i];
                int nx = curX+dx[i];
                int ny = curY+dy[i];

                if(nz<0||nz>=L||nx<0||nx>=R||ny<0||ny>=C)continue;
                if(dist[nz][nx][ny] >= 0) continue;
                if(map[nz][nx][ny] == '#')continue;
                dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
                q.push({nz,{nx,ny}});
            }
        }

        if(!flag) cout << "Trapped!" << '\n';
        else{
            cout << "Escaped in " << ans << " minute(s)." << '\n';
        }
    }
    return 0;
}