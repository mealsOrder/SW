#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;    
const int MAX = 1001;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
int C,R,K;
void DFS(int y,int x,int cnt,int dir){
    visited[y][x]=true;
    map[y][x]=cnt;
    if(K == cnt) {
        cout << x+1 << " " <<  R-y <<'\n';
        return;
    }

    int ny = y+dy[dir];
    int nx = x+dx[dir];
    

    if(nx<0||nx>=C||ny<0||ny>=R||visited[ny][nx]){
        dir=(dir+1)%4;
        ny = y+dy[dir];
        nx = x+dx[dir];
    }
    
    DFS(ny,nx,cnt+1,dir);

}

int main(){

    cin >> C >>R>>K;
    if(K>R*C) {
        cout << 0 << '\n';
        return 0;
    }
    DFS(R-1,0,1,0);
    // for(int i=0;i<R;i++){
    //     for(int j=0;j<C;j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    
    return 0;
}