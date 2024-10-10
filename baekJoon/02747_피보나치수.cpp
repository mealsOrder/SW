#include<iostream>
#include<algorithm>

using namespace std;

const int MX = 46;
long long dp[MX];
int N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;

    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=N;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout << dp[N];
    return 0;
}