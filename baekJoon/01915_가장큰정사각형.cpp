#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int MX = 1001;

int a[MX][MX];
int dp[MX][MX];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }

    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dp[i][j] = a[i][j];
            if( a[i][j] && i>0 && j>0){
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
            }
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans * ans <<'\n';
    return 0;
}