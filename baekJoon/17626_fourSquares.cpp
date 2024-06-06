#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<cmath>
using namespace std;
int N;
const int MX = 50001;
int dp[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >>N;
    for(int i=1;i<=N;i++){
        // 초기값 설정, 최악의 경우 1의 제곱으로만 이루어져 있음
        dp[i] = i; 
        // 1부터 i의 제곱근까지 순회
        for(int j=1;j*j<=i;j++){
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }
    cout << dp[N];
    return 0;
}
