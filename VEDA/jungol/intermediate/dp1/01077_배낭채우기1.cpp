#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MX = 1001;
int dp[1001][10001];

int W[1001]; // 무게
int P[1001]; // 가치
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,L;
    cin >> N >>L;

    for(int i=1;i<=N;i++){
        int a,b;
        cin >> a >>b;
        W[i] = a;
        P[i] = b;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=L;j++){
            if( j < W[i]) dp[i][j] = dp[i-1][j];
        
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j - W[i]]+P[i]);
                if(W[i]*2<=j){
                    dp[i][j] = max(dp[i][j],dp[i][j-W[i]]+P[i]);
                }
            }
        }
    }
    cout << dp[N][L] << '\n';
    return 0;
}