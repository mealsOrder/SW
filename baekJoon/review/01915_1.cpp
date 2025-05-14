#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<cstring>
using namespace std;

const int MX = 1001;
string str[MX];
int dp[MX][MX];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,M;
    cin >> N >> M;

    for(int i=0;i<N;i++)cin >> str[i];

    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(str[i][j] == '1'){
                if(i == 0 || j==0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = min ( {dp[i-1][j] , dp[i][j-1] , dp[i-1][j-1]}) +1;
                }
                ans = max(ans,dp[i][j]);
            }
        }
    }
    cout << ans * ans << '\n';

    return 0;
}
