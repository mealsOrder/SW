#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


const int MAX = 1001;
const int A = 10007;
int dp[MAX];

int main(){
	
	int N;
	int ans=0;
	cin >> N;
	
	dp[1]=1%A;
	dp[2]=2%A;
	for(int i=3;i<=N;i++){
		dp[i] = (dp[i-2]+dp[i-1])%A;
	}
	
	cout << dp[N] << endl;
	return 0;
}