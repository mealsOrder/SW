#include<iostream>
#include<vector>
#include<algorithm>
const int MX = 1000001;
int dp[MX];
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    dp[0] = 0;
    dp[1] = 0;
    for(int i=2;i<=N;i++){
        dp[i] = dp[i-1]+1;
        if(i%2==0){
            dp[i]=min(dp[i/2]+1,dp[i]);
        }
        if(i%3==0){
            dp[i] = min(dp[i/3]+1,dp[i]);
        }
    }

    //for(int i=1;i<=N;i++) cout << dp[i] << " ";
    cout << dp[N];
    return 0;
}