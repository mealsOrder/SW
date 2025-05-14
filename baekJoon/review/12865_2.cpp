#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<cstring>
using namespace std;
const int MX = 101;
int dp[MX][100001];
int W[MX];
int V[MX];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,K;
    cin >> N >> K;

    for(int i=1;i<=N;i++){
        cin >> W[i] >> V[i];
    }

    for(int i=1;i<=N;i++){
        for(int j=0;j<=K;j++){
            if(j>=W[i]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]]+V[i]);
            }
            else{
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
            }
        }
    }
    cout << dp[N][K] << '\n';

    // cout << '\n';
    // for(int i=0;i<=N;i++){
    //     for(int j=0;j<=K;j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}
