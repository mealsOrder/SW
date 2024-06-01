#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 301 ;
int dp[MX];
int arr[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >>N;
    for(int i=1;i<=N;i++) cin >> arr[i];
    
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    dp[3] = max(arr[1]+arr[3],arr[2]+arr[3]);
    for(int i=4;i<=N;i++){
        dp[i] = max(dp[i-3]+arr[i-1]+ arr[i],dp[i-2]+ arr[i]);
    }

    cout << dp[N];

    return 0;
}