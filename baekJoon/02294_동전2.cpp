#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int MX = 10001;
const int INF = 1e9;
int dp[MX];
int coin[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N,K;
    cin >> N >> K;

    for(int i=1;i<=N;i++) cin >> coin[i];
    fill(dp,dp+K+1,INF);
    dp[0] = 0;

    for(int i=1;i<=N;i++){
        for(int j=coin[i];j<=K;j++){
            dp[j] = min( dp[j] , dp[j-coin[i]] +1);
        }
    }

    if(dp[K] == INF) cout << -1 << '\n';
    else cout << dp[K] << '\n';
    
    return 0;
}