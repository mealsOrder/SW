#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 10;
int N,M;
int ans;
int map[MX][MX];
int clone[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

queue<pair<int,int>>virus;
void BFS(){
    queue<pair<int,int>>q=virus;
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M&&clone[nx][ny]==0){
                clone[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }
}

void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            clone[i][j] = map[i][j];
        }
    }
}

int getArea(){
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(clone[i][j] == 0)cnt++;
        }
    }
    return cnt;
}
void back(int x){
    if(x == 3){
        init();
        BFS();
        int safe = getArea(); 
        ans = max(ans,safe);
        return;
    }
    else{
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j] == 0){
                    map[i][j] = 1;
                    back(x+1);
                    map[i][j] = 0;
                }
            }
        }        
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j] == 2) virus.push({i,j});
        }
    }

    back(0);

    cout << ans << '\n';
    return  0;
}