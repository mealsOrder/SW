#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int a[101][101];
int sc;
float sum[101];

string g[]={"A+","A0","A-","B+","B0","B-","C+","C0","C-","D0"};

int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		int N,K,ans=0;
		cin >> N >> K;
		
		for(int i=1;i<=N;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
			}
		}
		
		for(int i=1;i<=N;i++){
			sum[i] = 0.35*a[i][1] + 0.45*a[i][2] +0.2*a[i][3];
		}		
		
		float sc = sum[K];
		int nt = N/10;
		sort(sum+1,sum+N+2,greater<int>());
		
		for(int i=1;i<=N;i++){
			if(sc == sum[i]){
				ans = i;
			}
		}		

		cout << "#" << t << " " << g[ ans*nt-1 ] << endl;
		
	}
	
	
}