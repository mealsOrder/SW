#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 36;

long long dp[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;

    cin >> N;

    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=N+1;i++){
        for(int j=0;j<i;j++){
            dp[i] += dp[j]*dp[i-j];
        }  
    }

    cout << dp[N+1] << '\n';
    return 0;
}