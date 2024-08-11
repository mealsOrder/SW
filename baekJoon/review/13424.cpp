#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MX = 101;
const int INF = 987987987;
int map[MX][MX];
int room[MX];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    while(T--){
        int ans=0,dist=INF;
        int N,M,K;
        cin >> N >>M;

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                map[i][j]=INF;
            }
        }
        while(M--){
            int a,b,c;
            cin >> a >> b >> c;
            map[a][b]=c;
            map[b][a]=c;
        }
        cin >> K;
        for(int i=1;i<=K;i++){
            cin >> room[i];
        }
        // 플로이드 워셜의 최적화
        for(int i=1;i<=N;i++) map[i][i]=0;
        for(int k=1;k<=K;k++){
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    map[i][j] = min(map[i][j],map[i][k]+map[k][j]);
                }
            }
        }
        
        for(int i=1;i<=N;i++){
            int tmp = 0;
            for(int j=1;j<=K;j++){
                tmp+=map[i][room[j]];
            }
            if(dist>tmp){
                dist = tmp;
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
