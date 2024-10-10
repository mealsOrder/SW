#include<iostream>
#include<algorithm>

using namespace std;

const int MX = 1001;
int N;
int dp[MX];
int arr[MX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    dp[0]=0;
    for(int i=1;i<=N;i++){
        dp[i]=arr[i];
        for(int j=1;j<=i;j++){
            dp[i] = min(dp[i],dp[i-j]+dp[j]);
        }
    }
    cout << dp[N];
    return 0;
}