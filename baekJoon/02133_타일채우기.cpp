#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 31;
int dp[MX];
int main(){
	int N;
    cin >> N;
    dp[0]=1;
    dp[1]=0;
    dp[2]=3;
    dp[3]=0;
    for(int i=4;i<=N;i++){
        if(i%2==0){
            dp[i] = dp[i-2]*4 - dp[i-4];
        }   
    }

    cout << dp[N] << '\n';
	return 0;
}