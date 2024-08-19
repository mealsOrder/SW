#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,K,W,V;
    cin >> N >> K ;

    vector<int>dp(K+1,0);
    for(int i=0;i<N;i++){
        cin >> W >> V;
        for(int j=K;j>=W;j--){ // 안되면 --j로
                dp[j] = max(dp[j],dp[j-W]+V);
        }
    }
    cout << *max_element( dp.begin(),dp.end() );
    return 0;
}