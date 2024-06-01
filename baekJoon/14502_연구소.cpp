#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int MX = 10;
int map[MX][MX];
int clo[MX][MX];
int N,M;
int res;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
queue<pair<int,int>>virus;
void BFS(){
    queue<pair<int,int>>q = virus;

    while(!q.empty()){
        int curX=q.front().first;
        int curY=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M&&clo[nx][ny]==0){
                clo[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }
}

void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            clo[i][j]=map[i][j];
        }
    }
}

int getArea(){
    int safe=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(clo[i][j] == 0)safe++;
        }
    }
    return safe;
}

void back(int x){ // x : 벽 개수
    if(x==3){
        init();
        BFS();
        res = max(res,getArea());
        return;
    }
    else{
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if( map[i][j] == 0){
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

    cin >> N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                virus.push({i,j});
            }

        }
    }
    back(0);
    cout << res;
    return 0;
}