#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 501;
int dp[MX];
int mxNum;
vector<pair<int,int>>v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end());

    for (int i = 0; i < N; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if(v[i].second > v[j].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
            
        }
        mxNum = max(mxNum,dp[i]);
    }
    cout << N - mxNum;
    return 0;
}