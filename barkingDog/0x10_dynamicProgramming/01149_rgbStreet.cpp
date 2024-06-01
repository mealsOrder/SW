#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MX = 1001;
int dp[MX][3];
int arr[MX][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >>N;
    for(int i=1;i<=N;i++){
        cin >> arr[i][0]>> arr[i][1]>> arr[i][2];
    }
    dp[0][0] = 0;
    dp[1][0] = arr[1][0];
    dp[1][1] = arr[1][1];
    dp[1][2] = arr[1][2];

    for(int i=2;i<=N;i++){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + arr[i][2];
    }

    int ans = min({dp[N][0],dp[N][1],dp[N][2]});
    cout << ans;
    return 0;
}