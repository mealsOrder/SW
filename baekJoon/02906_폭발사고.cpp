#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int MX = 1001;
const int K = 10301;
int dp[MX][MX];
int N,A,B;
int mod(int x){
    return (x + K)%K;
}
int solve(int n, int a){
    if(a == n) return 1;
    if(a > n/2) return 0;
    int &ret = dp[n][a];
    if(ret != -1) return ret;
    ret = mod(solve(n-a,a));
    if(a+1 <=n/2) ret = mod(ret+solve(n,a+1));
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> N >> A >> B;
    int ans = 0;
    for(int i=A;i<=N-B;i++){
        for(int j=i;j<=N-B;j++){
            ans = mod( ans+solve(i,A)*solve(N-j,B));
        }
    }
    cout << ans;
    return  0;
}