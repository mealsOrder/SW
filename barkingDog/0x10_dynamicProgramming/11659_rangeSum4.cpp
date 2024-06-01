#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 100001;

int N,M;
int dp[MX];
int arr[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >>N>>M;
    /**
     * 이 방법을 Prefix Sum 이라는 기법이
     * */    
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        dp[i] = (dp[i-1] +arr[i]);
    }

    while(M--){
        int a,b;
        cin >> a >> b;
        if(a == b) cout << arr[a]<<'\n';
        else cout << dp[b] - dp[a-1] << '\n';
    }
    return 0;
}