#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 10007;
const int MOD = 10007;
int N;
int dp[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >>N;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=N;i++){
        dp[i] = (dp[i-1] + dp[i-2])%MOD;
    }

    cout << dp[N];

    return 0;
}