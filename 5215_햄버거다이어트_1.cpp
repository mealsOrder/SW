#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[22][1002];

int N,L;

int cnt[22];
int cal[22];


void init(){
	for(int i=0;i<=N;i++){
		cnt[i]=0;
		cal[i]=0;
		for(int j=0;j<=N;j++){
			dp[i][j]=0;
		}
	}
}

int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		cin >> N >> L;
		
		init();
		for(int i=1;i<=N;i++){
			cin >> cnt[i] >> cal[i];
		}
		
		for(int i=1;i<=N;i++){
			for(int j=1;j<=L;j++){
				
				// do not input cal[i]
				if(j<cal[i]){
					dp[i][j] = dp[i-1][j];
				}
				else{
					dp[i][j] = max( dp[i-1][j],dp[i-1][j-cal[i]]+cnt[i] );
				}
				
			}
		}
		
		
		

		cout << "#" << t << " " << dp[N][L] << endl;
		
	}
	


}