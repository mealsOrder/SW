#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,ans=0;
    cin >> N;

    vector<int>dp(N+1);
    vector<int>pre(N+1);

    dp[1] = 0;

    for(int i=2;i<=N;i++){
        dp[i] = dp[i-1]+1;
        pre[i] = i-1;
        if(i%3==0 && dp[i]>dp[i/3]+1){
            dp[i] = dp[i/3]+1;
            pre[i] = i/3;
        }

        if(i%2==0 && dp[i]>dp[i/2]+1){
            dp[i] = dp[i/2]+1;
            pre[i] = i/2;
        }
    }

    cout << dp[N] << '\n';

    while(N){
        
        cout << N << ' ';
        N = pre[N];
    }
    return 0;
}