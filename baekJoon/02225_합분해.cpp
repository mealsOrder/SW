#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;
const int MX = 201;
const int MOD = 1000000000;
int dp[MX][MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,K;
    cin >> N >> K;

    // init
    for(int i=0;i<=N;i++){
        dp[i][1] = 1;
    }

    // dp
    for(int i=0;i<=N;i++){
        for(int j=2;j<=K;j++){
            if(i==0) dp[i][j] = 1;
            else dp[i][j] = (dp[i][j-1] + dp[i-1][j])%MOD;
        }
    }

    cout << dp[N][K] << '\n';
    return 0;
}