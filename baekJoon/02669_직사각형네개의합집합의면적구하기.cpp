#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
using namespace std;
const int MX = 101;
bool vis[MX][MX];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<4;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int y = y1; y <y2;y++){
            for(int x = x1;x<x2;x++){
                vis[y][x] = true;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
           if(vis[i][j]) ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
