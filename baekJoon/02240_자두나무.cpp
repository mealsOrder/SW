#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
const int MX = 1001;
int dp[MX][35];
int a[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,W;
    cin >> N >> W;
    int first=0, second=0;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    
    for(int i=1;i<=N;i++){
        if(a[i] == 1){
            first++;
        }
        dp[i][0] = first;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=W;j++){
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + (1+j%2 == a[i]);
        }
    }
    
    cout << *max_element(dp[N],dp[N]+W+1);

    return 0;
}