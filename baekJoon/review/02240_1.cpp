#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
#include<climits>
using namespace std;
const int MX = 1001;
int a[MX];
int dp[MX][31];

int T,W;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> T >> W;
    int first=0;
    for(int i=1;i<=T;i++){
        cin >> a[i];
        if(a[i] == 1) first++;
        dp[i][0] = first;
    }

    for(int i=1;i<=T;i++){
        for(int j=1;j<=W;j++){
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + (1+j%2 == a[i]);
        }
    }
    
    cout << *max_element(dp[T],dp[T]+W+1);
    return 0;
}