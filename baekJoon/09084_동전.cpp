#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while(T--){
        int N,M;
        cin >> N;
        vector<int>coin(N);
        for(int i=0;i<N;i++){
            cin >> coin[i];
        }
        cin >> M;

        vector<int>dp(M+1,0);
        dp[0]=1;

        for(int i=0;i<N;i++){
            for(int j=coin[i];j<=M;j++){
                dp[j] += dp[j-coin[i]];
            }
        }
        cout << dp[M] << '\n';
    }

    return 0;
}
