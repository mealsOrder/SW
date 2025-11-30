#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
const int MX = 1500001;
const int INF = 1e9;
int t[MX];
int p[MX];
int dp[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for(int i=1;i<=N;i++){
        cin >> t[i] >> p[i];
    }

    for(int i=N;i>=1;i--){
        if(i+t[i] <= N+1) dp[i] = max({dp[i+t[i]] + p[i],dp[i+1] });
        else dp[i] = dp[i+1];
    }

    int ans = *max_element(dp+1,dp+N+1);
    cout << ans << '\n';
    return 0;
}