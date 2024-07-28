#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MX = 51;
string map[MX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int R,C;
int EX,EY;
queue<pair<int,int>>fire;
queue<pair<int,int>>hero;
int fdist[MX][MX];
int hdist[MX][MX];

void init(){
    for(int i=0;i<=R;i++){
        for(int j=0;j<=C;j++){
            fdist[i][j] = -1;
            hdist[i][j] = -1;
        }
    }
}

void burn(){
    while(!fire.empty()){
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0||nx>=R||ny<0||ny>=C)continue;
            if(fdist[nx][ny]>=0)continue;
            if(map[nx][ny] == 'X')continue;
            if(map[nx][ny] == 'D')continue;
            fdist[nx][ny] = fdist[x][y]+1;
            fire.push({nx,ny});        
        }
    }
}

int BFS(){
    while(!hero.empty()){
        int x = hero.front().first;
        int y = hero.front().second;
        hero.pop();

        if(x == EX && y == EY) return hdist[EX][EY];

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0||nx>=R||ny<0||ny>=C)continue;
            if(map[nx][ny] == 'X')continue;
            if(hdist[nx][ny] >= 0)continue;
            if(fdist[nx][ny] != -1 && fdist[nx][ny] <= hdist[x][y]+1)continue;
            hdist[nx][ny] = hdist[x][y] + 1;
            hero.push({nx,ny});
        }
    }

    return -1;
}
int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    cin >> R>>C;

    for(int i=0;i<R;i++){
        cin >> map[i];
    }
    init();
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j] == 'S'){
                hero.push({i,j});
                hdist[i][j] = 0;
            }
            if(map[i][j] == '*'){
                fire.push({i,j});
                fdist[i][j] = 0;
            }
            if(map[i][j] == 'D'){
                map[i][j] == '.';
                EX = i;
                EY = j;
            }
        }
    }
    burn();
    
    int ans = BFS();
    if(ans == -1) cout << "impossible\n";
    else cout << ans << '\n';
	return 0;
}