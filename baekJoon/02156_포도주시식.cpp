#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 10001;

int dp[MAX];
int A[MAX];


int main(){
	
	int N;
	cin >> N;
	
	
	for(int i=1;i<=N;i++){
		cin >> A[i];
	}
	
	dp[1]=A[1];
	dp[2]=A[1] + A[2];
	for(int i=3;i<=N;i++){
		dp[i] = max( dp[i-1], max(dp[i-2]+A[i] , dp[i-3]+A[i-1]+A[i]));
	}
	
	cout << dp[N] << endl;
	
	return 0;
}