#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MX = 101;
int dp[MX][10001];
int A[MX];
int C[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,M,ans=987987987;
    cin >> N >> M;

    for(int i=1;i<=N;i++){
        cin>> A[i]; 
    }
    for(int i=1;i<=N;i++){
        cin>> C[i]; 
    }

    for(int i=1;i<=N;i++){
        for(int j=0;j<=10000;j++){
            if(C[i]>j)dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-C[i]]+A[i]);
            }
            // 비활성화 최소 비용
            if(dp[i][j] >=M) ans = min(ans,j);
        }
    }

    cout << ans << '\n';
    return 0;
}