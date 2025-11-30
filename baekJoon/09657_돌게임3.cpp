#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int MX = 1005;
int N;
int dp[MX]; // 돌이 idx개 있을때 선공이 이기면 0, 후공이 이기면 1
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;

    fill(dp,dp+MX,-1);

    dp[1]=0;
    dp[2]=1;
    dp[3]=0;
    dp[4]=0;

    for(int i=5;i<=N;i++){
        for(int d : {1,3,4}){
            if(dp[i-d] == 1){
                dp[i] = 0;
                break;
            }
            else dp[i]=1;
        }
    }
    if(dp[N] == 0) cout << "SK";
    else cout << "CY";
    return 0;
}