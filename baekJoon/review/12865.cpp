#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MX = 101;
int dp[MX][100001];
int V[MX];
int W[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,K;
    cin >> N >> K;

    for(int i=1;i<=N;i++){
        cin>> W[i] >> V[i];
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            if(W[i]>j)dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-W[i]]+V[i]);
            }
        }
    }

    cout << dp[N][K]<< '\n';
    return 0;
}