#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MX = 101;
int N,K;
int dp[MX][100001];
int W[MX];
int V[MX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for(int i=1;i<=N;i++){
        cin >> W[i] >> V[i];
    }
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<=K;j++){
            // 최대 무게 보다 현재 무게가 클 경우
            if(W[i] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max( dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
            }
        }
    }

    cout << dp[N][K];
    return 0;
}