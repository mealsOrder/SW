#include<iostream>
#include<vector>
#include<algorithm>


int a[100][100];
int dp[100];

using namespace std;


int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		int N,M;
		cin >> N >> M;
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin >> a[i][j];
			}
		}
		
		// init N=3 M=2
		
		int ans=0;
		for(int si=0;si<N-M+1;si++){
			for(int sj=0;sj<N-M+1;sj++){
				
				int cnt=0;
				
				for(int i=si;i<si+M;i++){
					for(int j=sj;j<sj+M;j++){
						cnt+=a[i][j];
					}
				}
				if(cnt>ans){
					ans = cnt;
				}
			}
		}
		
		cout << "#" << t << " " << ans << endl;
		
	}
	


}