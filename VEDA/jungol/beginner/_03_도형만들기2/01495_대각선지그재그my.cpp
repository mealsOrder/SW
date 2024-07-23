#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

// 미완성 코드

const int MX = 101;
int arr[MX][MX];
bool vis[MX][MX];
int N;
int dx[] = {1,-1,0,1};
int dy[] = {0,1,1,-1};

void init(){
    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=N+1;j++){
            arr[i][j] = 0;
        }
    }
}
void DFS(int x,int y,int cnt,int dir){

    arr[x][y] = cnt;

    if(cnt == N*N)return;
    int nx = x+dx[dir];
    int ny = y+dy[dir];
    
    if(nx<0||nx>=N||ny<0||ny>=N){
        dir = (dir+1)%4;
    }
    
    nx = x+dx[dir];
    ny = y+dy[dir];
    DFS(nx,ny,cnt+1,dir);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    init();    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            arr[i][j] = 0;
        }
    }

    DFS(1,1,1,0);

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}