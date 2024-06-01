#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
const int MX = 501;

int dp[MX][MX];
int arr[MX][MX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            cin >> arr[i][j];
        }
    }
    dp[1][1] = arr[1][1];
    
    for(int i=2;i<=N;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + arr[i][j];
        }
    }
    int res=0;
    for(int i=1;i<=N;i++){
        res = max(dp[N][i],res);
    }
    cout << res;
    return 0;
}