#include<iostream>

using namespace std;

const int MAX = 1001;
const int MOD = 10007;

int dp[MAX];
int arr[MAX][MAX];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	
	for(int i=0;i<=9;i++){
		arr[1][i] = 1;
	}
	
	for(int i=2;i<=N;i++){
		for(int j=0;j<=9;j++){
			arr[i][j] = (arr[i][j-1]+arr[i-1][j])%MOD;
		}
	}	
	
	int ans = 0;
	for(int i=0;i<10;i++){
		ans += (arr[N][i]%MOD);
	}
	
	cout << ans%MOD << '\n';
	
	
	return 0;
}