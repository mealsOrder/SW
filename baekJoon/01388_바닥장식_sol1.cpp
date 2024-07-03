#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;
const int MX = 51;
int N,M;
string map[MX];
void DFS(int x,int y,char c){
    // 가로선인 경우
    if(c == '-'){
        map[x][y] = 0; // 지도의 값을 0 으로 바꾸면서 방문 표시
        // 오른쪽이 가로선이면 DFS
        if(map[x][y + 1] == '-') DFS(x,y+1,map[x][y+1]);
    }
    // 세로선인 경우
    if(c == '|'){
        map[x][y] = 0; // 지도의 값을 0 으로 바꾸면서 방문 표시
        // 아래쪽이 세로선이면 DFS
        if(map[x+1][y] == '|') DFS(x+1,y,map[x+1][y]);
    }
}  
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int ans = 0;
    cin >> N>>M;
    for(int i=0;i<N;i++){
        cin >> map[i];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]){
                DFS(i,j,map[i][j]);
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}