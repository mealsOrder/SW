#include <string>
#include <vector>

using namespace std;
const int MX = 501;
int dp[MX][MX];
int solution(vector<vector<int>> tri) {
    int ans = 0;
    dp[0][0] = tri[0][0];

    dp[1][0] = dp[0][0] + tri[1][0];
    dp[1][1] = dp[0][0] + tri[1][1];
    
    int n = tri.size();
    for(int i=2;i<tri.size();i++){
        dp[i][0] = dp[i-1][0] + tri[i][0];
        for(int j=0;j<tri[i].size();j++){
           dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + tri[i][j];     
        
        }
    }
    
    for(int i=0;i<n;i++){
        ans = max(ans,dp[n-1][i]);
    }
    return ans;
}