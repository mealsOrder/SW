#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

const int MX = 8;
int ans = 99999999;
int N,M;
int arr[MX][MX];
int dp[MX][MX][4];
int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    memset(dp,10000,sizeof(dp));
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=1;i<=M;i++) dp[1][i][1] = dp[1][i][2]= dp[1][i][3] = arr[1][i];

    for(int i=2;i<=N;i++){
        for(int j=1;j<=M;j++){
            //dp[i][j] = arr[i][j] + min(dp[i-1][j-1],dp[i-1][j+1]);
            dp[i][j][1] = min(dp[i - 1][j + 1][2], dp[i - 1][j + 1][3]) + arr[i][j];
			dp[i][j][2] = min(dp[i - 1][j][1], dp[i - 1][j][3]) + arr[i][j];
			dp[i][j][3] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + arr[i][j];
        }
    }

    for(int i=1;i<=M;i++){
        ans = min(ans,min(dp[N][i][1],min(dp[N][i][2],dp[N][i][3])));
    }
    cout << ans << '\n';
	return 0;
}