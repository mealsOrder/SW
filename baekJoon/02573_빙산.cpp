#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int MX = 301;
int N,M,year;
int map[MX][MX];
bool vis[MX][MX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool check(int i,int j){
    return (i>=0 && i<N && j>=0 && j<M);
}

void init(){
    for(int i=0;i<N;i++){
        fill(vis[i],vis[i]+M,0);
    }
}

void melt(){
    int zero[MX][MX]= {0,};
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] == 0)continue;
            for(int dir = 0;dir<4;dir++){
                int nx = i+dx[dir];
                int ny = j+dy[dir];
                if(check(nx,ny) && map[nx][ny] == 0) zero[i][j]++;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            map[i][j] = max(0,map[i][j] - zero[i][j]);
        }
    }
}

// 0: 다녹음, 1: 한덩이, 2: 분리됨
int BFS(){
    int x = -1, y = -1;
    int cnt1 = 0; // 빙산의 개수

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]){
                x =i;
                y =j;
                cnt1++;
            }
        }
    }
    if(cnt1 == 0) return 0;
    int cnt2 = 0; // x,y 와 붙어있는 빙산의 수

    queue<pair<int,int>>q;
    vis[x][y] = true;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        cnt2++;
        for(int i=0;i<4;i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];


            if(nx<0 || nx>=N || ny<0 || ny>=M)continue;
            if(vis[nx][ny])continue;
            if(map[nx][ny] <=0 )continue;
            vis[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    if(cnt1 == cnt2) return 1;
    return 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }

    while(true){
        year++;
        melt();
        init();
        int chk = BFS();
        if(chk == 0){
            cout << 0;
            return 0;
        }
        else if(chk == 1)continue;
        else break;
    }
    
    cout << year;

    return 0;
}