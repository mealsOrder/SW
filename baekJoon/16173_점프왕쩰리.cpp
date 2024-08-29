#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MX = 4;
int N;
int dx[]={0,1};
int dy[]={1,0};
int arr[MX][MX];
bool flag;
void DFS(int x,int y,int cnt,int dir){
    
    if(cnt == 0){
        if(arr[x][y] == 0) return;
        else if(x == N-1 && y == N-1){
            //cout << "HaruHaru";
            flag = true;
            return;
        }
        else {
            cnt = arr[x][y];
        }
    }
    
    int nx = x+dx[dir];
    int ny = y+dy[dir];
    
    if(nx<0||nx>=N||ny<0||ny>=N){
        dir = (dir+1)%2;
        nx = x+dx[dir];
        ny = y+dy[dir];
    }

    DFS(nx,ny,cnt-1,dir);
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
   
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
   
 
    DFS(0,0,0,0);
    if(flag){
        cout << "HaruHaru";
        return 0;
    }
    DFS(0,0,0,1);
    if(flag) {
        cout << "HaruHaru";
        return 0;
    }
    else cout << "Hing";

    return 0;
}