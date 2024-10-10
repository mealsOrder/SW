#include<iostream>
#include<algorithm>

using namespace std;

const int MX = 10001;
int N;
int dp[MX][4];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    dp[1][1] = 1;

    dp[2][1] = 1;
    dp[2][2] = 1;

    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;


    for(int i=4;i<=MX;i++){
        dp[i][1] = 1;
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }

    while(T--){
        cin >> N;
        cout << dp[N][1]+dp[N][2]+dp[N][3] << '\n';
    }
    return 0;
}