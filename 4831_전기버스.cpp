#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int dp[101];
int flag[101]; // charge
int cnt;

void init(){
	for(int i=0;i<=100;i++){
		dp[i]=0;
		flag[i]=0;
	}
}

int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		int K,N,M;
		cin >> K >> N >> M; 
		init();
		for(int i=1;i<=M;i++){
			cin >> flag[i];
	
		}
		
		int ans = 0;
		int s = 0;
		for(int i=1;i<=M+1;i++){
			
			if(flag[i] - flag[i-1] > K){
				ans = 0;
				break;
			}
			if(flag[i] - s > K){
				s = flag[i-1];
				ans+=1;
			}
		}
		cout << "#" << t << " " << ans << endl;
		
	}
	


}