#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
using namespace std;

int dp[21][10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        int N,M;
        cin >> N;

        vector<int>arr(N+1);

        for(int i=1;i<=N;i++)cin >> arr[i];

        cin >> M;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;

        for(int i=1;i<=N;i++){
            for(int j=0;j<=M;j++){
                dp[i][j] = dp[i-1][j];

                if(j-arr[i] >=0) dp[i][j] += dp[i][j-arr[i]];
            }
        }
        cout << dp[N][M] << '\n';
    }

    return 0;
}