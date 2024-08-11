#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
// 오답 코드
const int MX = 101;
const int INF = 987987987;
int map[MX][MX];
int room[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;

    // tc
    while(T--){
        int dist = INF;
        int N,M,K;
        int ans = 0;
        cin >> N >> M;
        // 경로 초기화
        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++){
                if(i==j)map[i][j] = 0;
                else map[i][j] = INF;
            }
        }
        
        while(M--){
            int a,b,c;
            cin >> a>>b>>c;
            map[a][b]=c;
            map[b][a]=c;
        }
        cin >> K;
        // 방 초기화
        for(int i=1;i<=K;i++)room[i] = 0;
        
        // 방 입력
        for(int i=1;i<=K;i++){
            cin >> room[i];
        }
        for(int k=1;k<=N;k++){
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    if(map[i][j] > map[i][k]+map[k][j]){
                        map[i][j] = map[i][k]+map[k][j];
                    }
                }
            }
        }

        for(int i=1;i<=N;i++){
            int tmp=0;
            for(int j=1;j<=K;j++){
                tmp+=map[i][room[j]];
            }
            if(dist>tmp){
                dist=tmp;
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}