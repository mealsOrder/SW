#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 3;
int N;
int map[MX][MX];
int chk(int x,int y){
    if(x == N-1 && y == N-1) return 1;
    if(x<0||x>=N||y<0||y>=N) return 0;
    int ans = 0;
    if(x + map[x][y] > x) ans = max(ans,chk(x + map[x][y], y ));
    if(y + map[x][y] > y) ans = max(ans,chk(x, y + map[x][y] ));

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
    if(chk(0,0))cout << "HaruHaru";
    else cout << "Hing";
    return 0;
}