#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<cstring>
using namespace std;

const int MX = 1001;
int dp[MX][MX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string a,b;
    cin >> a >> b;

    int aLen = a.length();
    int bLen = b.length();

    for(int i=1;i<=aLen;i++){
        for(int j=1;j<=bLen;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            dp[i][j] = max({dp[i-1][j],dp[i][j-1],dp[i][j]});
        }
    }

    cout << dp[aLen][bLen] << '\n';
    
    return 0;
}
