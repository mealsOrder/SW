#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 91;
long long dp[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >>N;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3;i<=N;i++){
        dp[i]= dp[i-1]+dp[i-2];
    }    
    cout << dp[N] << '\n';
    return 0;
}