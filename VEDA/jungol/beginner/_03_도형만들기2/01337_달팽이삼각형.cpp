#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MX = 101;
int N;
int dx[] = {1,0,-1};
int dy[] = {1,-1,0};
int arr[MX][MX];
void DFS(int x,int y,int cnt,int dir){

    arr[x][y] = cnt%10;
    int nx = x+dx[dir];
    int ny = y+dy[dir];
    if(cnt == N*(N+1)/2)return;

    if(nx<0 || nx>=N || ny<0 || ny>=N|| arr[nx][ny]>0 ){
        dir = (dir+1)%3;
        nx = x+dx[dir];
        ny = y+dy[dir];
    }
    arr[nx][ny] = (cnt+1)%10;
    DFS(nx,ny,cnt+1,dir);

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    DFS(0,0,0,0);

    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}