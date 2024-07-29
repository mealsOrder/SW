#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 501;
const int INF = 999999999; // 왜 INT_MAX 로 하면 안되는거지?
int map[MX][MX];
int N,M;

void func(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    int ans=0;
    
    // init
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            map[i][j] = INF;
        }
    }
    
    while(M--){
        int a,b;
        cin >> a>>b;
        map[a][b] = 1;
    }

    func();

    for(int i=1;i<=N;i++){
        int cnt=0;
        for(int j=1;j<=N;j++){
            if(map[i][j] != INF || map[j][i] != INF) cnt++;                
        }
        if(cnt == N-1) ans++;
    }

    cout << ans << '\n';
    return 0;
}