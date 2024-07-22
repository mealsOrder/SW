#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
const int MX = 101;
int map[MX][MX];
int N;
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

void DFS(int x,int y,int cnt, int dir){
    map[x][y] = cnt;
    if(cnt == N*N)return;

    int nx = x+dx[dir];
    int ny = y+dy[dir];

    if(nx<0||nx>=N||ny<0||ny>=N||map[nx][ny]>0){
        dir = (dir+1)%4;
        nx = x+dx[dir];
        ny = y+dy[dir];
    }
    DFS(nx,ny,cnt+1,dir);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    DFS(0,N-1,1,0);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }


    return 0;
}