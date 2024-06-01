#include<iostream>
#include<vector>
#include<algorithm>
const int MX = 1000001;
int dp[MX];
int pre[MX];
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
        pre[i] = i -1;
        if(i%2==0 && dp[i] > dp[i/2]+1) {
            dp[i] = dp[i/2]+1;
            pre[i] = i/2;
        }
        
        if(i%3==0 && dp[i] > dp[i/3]+1) {
            dp[i] = dp[i/3]+1;
            pre = i/3;
        }
    
    }
    cout << dp[N]<'\n';
    int cur = N;
    while(true){
        cout << cur << ' ';
        if(cur == 1) break;
        cur = pre[cur];
    }
    return 0;
}