#include<iostream>
#include<queue>
using namespace std;
const int MAX = 101;

int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int N,X,Y,R;
queue<pair<int,int>>q;
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            map[i][j] = 0;
        }
    }
}

void BFS(int x, int y){
    visited[x][y] = true;
    map[x][y] = 0;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        if(map[curX][curY] == R)return;

        for(int i=0;i<4;i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<N&&!visited[nx][ny]&&!map[nx][ny]){
                visited[nx][ny]=true;
                map[nx][ny]=map[curX][curY]+1;
                q.push({nx,ny});
            }
        }

    }
    
}

int main() {
    cin >>N>>X>>Y>>R;
    init();
    BFS(X-1,Y-1);
    map[X-1][Y-1] = -1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]== -1){
                cout << "x ";
            }
            else{
                cout << map[i][j] << " ";
            }
        }
        cout << '\n';
    }    

    return 0;
}