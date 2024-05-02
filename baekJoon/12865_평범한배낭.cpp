#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int dp[110][100005];
int w[110];
int v[110];
int N,K;

void init(){
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			dp[i][j] = 0;
		}
	}
}


int main(){
	

	
	cin >> N >> K;
	
	for(int i=1;i<=N;i++){
		cin >> w[i] >> v[i];
		
	}
	
	init();
	for(int i=1;i<=N;i++){
		for(int k=1;k<=K;k++){
			// do Not iNput w[i]
			if(w[i]>k){
				dp[i][k] = dp[i-1][k];
			}
			// iNput w[i]
			else {
				dp[i][k] = max( dp[i-1][k-w[i]]+v[i],dp[i-1][k] );
			}
		
		}
	}
		
	cout << dp[N][K] << endl;
	
}