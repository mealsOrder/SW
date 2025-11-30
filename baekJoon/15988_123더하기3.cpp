#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
using ll = long long;
const int MX = 1000001;
const int MOD = 1000000009;
ll dp[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;

    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    
    for(int i=4;i<=MX;i++){
        dp[i] = (dp[i-1] +dp[i-2]+dp[i-3])%MOD;
    }
    
    while(T--){
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}