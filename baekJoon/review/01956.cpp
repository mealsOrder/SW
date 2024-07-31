#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MX = 401;
const int INF = 987987987;

int V,E;
int path[MX][MX];

void func(){
    for(int k=1;k<=V;k++)
        for(int i=1;i<=V;i++)
            for(int j=1;j<=V;j++)
                if(path[i][j] > path[i][k] + path[k][j])
                    path[i][j] = path[i][k] + path[k][j];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> V >> E;

    for(int i=1;i<=V;i++)
        for(int j=1;j<=V;j++)
            if(i!=j)path[i][j] = INF;
    while(E--){
        int a,b,c;
        cin >> a >> b >> c;
        path[a][b]=c;
    }
    func();
    int ans = INF;
    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            if(i==j)continue;
            ans = min(ans,path[i][j]+path[j][i]);
        }
    }
    if(ans == INF) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}