#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// solving Time : 22 min

const int MAX = 10001;

int dp[21][MAX];
int kal[21];
int val[21];
int N,L;
void init(){
	for(int i=0;i<=N;i++){
		val[i]=kal[i]=0;
		for(int j=0;j<=L;j++){
			dp[i][j] = 0;
		}
	}
}

int main(){
	

    
	int TT;
	
	cin >> TT;
	
	for(int t=1;t<=TT;t++){
		
		int ans=0;
		init();
		cin >> N >> L;
		for(int i=1;i<=N;i++){
			cin >> val[i] >> kal[i];
		}
		
		
		for(int i=1;i<=N;i++){
			for(int j=1;j<=L;j++){
				
				if(j>kal[i]){
					dp[i][j] = max(dp[i-1][j-kal[i]] +val[i] ,dp[i-1][j] );
				}
				else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		
		ans = dp[N][L];
		cout << "#" << t << " " << ans << endl;
		
	}
	

	return 0;
}