#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 100001;

// over memory donot n*n arr >> n arr

int A[MAX][3];
int max_dp[2][3];
int min_dp[2][3];

int main(){
	
	int N;
	
	cin >> N;
	
	for(int i=1;i<=N;i++){
		
		cin >> A[i][0] >> A[i][1] >> A[i][2];
		
	}
	
	// init
//	max_dp[0][0] = A[0][0]; 
//	max_dp[0][1] = A[0][1];
//	max_dp[0][2] = A[0][2];
//	min_dp[0][0] = A[0][0]; 
//	min_dp[0][1] = A[0][1];
//	min_dp[0][2] = A[0][2];
	
	for(int i=1;i<=N;i++){
		max_dp[i%2][0] = max(max_dp[(i-1)%2][0],max_dp[(i-1)%2][1]) + A[i][0]; 
		max_dp[i%2][1] = max(max_dp[(i-1)%2][0],max(max_dp[(i-1)%2][1],max_dp[(i-1)%2][2])) + A[i][1]; 
		max_dp[i%2][2] = max(max_dp[(i-1)%2][1],max_dp[(i-1)%2][2]) + A[i][2]; 
		
		min_dp[i%2][0] = min(min_dp[(i-1)%2][0],min_dp[(i-1)%2][1]) + A[i][0]; 
		min_dp[i%2][1] = min(min_dp[(i-1)%2][0],min(min_dp[(i-1)%2][1],min_dp[(i-1)%2][2])) + A[i][1]; 
		min_dp[i%2][2] = min(min_dp[(i-1)%2][1],min_dp[(i-1)%2][2]) + A[i][2]; 
	
	}
	
	int mx = max(max(max_dp[N%2][0],max_dp[N%2][1]),max_dp[N%2][2]);
	int mn = min(min(min_dp[N%2][0],min_dp[N%2][1] ),min_dp[N%2][2]);
	
	
	cout << mx << " " << mn << endl;
	
	return 0;
}