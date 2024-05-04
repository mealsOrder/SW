#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


// solving time : 30 min 

int dp[22][10001];
int V[22];
int Kal[22];

int N,L;

void init(){
	
	for(int i=0;i<=N;i++){
		for(int j=0;j<=L;j++){
			dp[i][j] = 0;
		}
	}
	
}

int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		cin >> N >> L;
		
		for(int i=1;i<=N;i++){
			cin >> V[i];
			cin >> Kal[i];
		}
		
		init();
		
		for(int i=1;i<=N;i++){
			for(int j=1;j<=L;j++){
				
				// Can't input Kal[i]
				if(Kal[i] > j ){
					dp[i][j] = dp[i-1][j];
				}
				
				// Can input Kal[i], compair input one and do not input one
				else{
					dp[i][j] = max(dp[i-1][j-Kal[i]]+V[i],dp[i-1][j]);
				}
			}
		}
		
		cout << "#" << t << " " << dp[N][L] << endl;
	}
	
	
	
	
	
	return 0;
}