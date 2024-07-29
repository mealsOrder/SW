#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int MX = 100001;
const int MOD = 20100529;
long long dp[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    dp[1] = 1;
    dp[2] = 3;
    //dp[3] = 5;
    for(int i=3;i<=N;i++){
        dp[i] = (dp[i-2]*2 + dp[i-1])%MOD;
    }
    cout << dp[N];
    return 0;
}