#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 1001;
int dp[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >>N;
    dp[1] = 1;
    dp[2] = 3;
    for(int i=3;i<=N;i++){
        dp[i]= (dp[i-1]+dp[i-2]*2)%10007;
    }    
    cout << dp[N]%10007<<'\n';
    return 0;
}