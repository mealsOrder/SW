#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

// solving Time : 32 min
// pls be careful OutOfBounds
using namespace std;

const int MAX = 10001;

int val[21];
int kal[21];
int DP[21][MAX];

int main(){
	
	int T;
	cin >> T;
	for(int t=1;t<=T;t++){
		
		int N,L;
		
		
		memset(val,0,sizeof(val));
		memset(kal,0,sizeof(kal));
		memset(DP,0,sizeof(DP));
		
		cin >> N >> L;
		
		for(int i=1;i<=N;i++){
			cin >> val[i] >> kal[i];
		}
		
		for(int i=1;i<=N;i++){
			for(int j=1;j<=L;j++){
				if(j>kal[i]){
					DP[i][j] = max(  DP[i-1][j], DP[i-1][ j-kal[i] ]+ val[i]  );
				}
				else{
					DP[i][j] = DP[i-1][j];
				}
			}
		}
		
		
		cout << "#" << t << " " << DP[N][L] << endl;		
	}
	
	return 0;
}