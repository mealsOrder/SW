#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// solving Time : 26 min

const int MAX = 1001;
int b[MAX];
int N;


int main(){
	

	
	for(int t=1;t<=10;t++){
		
		
		cin >> N;
		int ans = 0;
		
		for(int i=0;i<N;i++){
			cin >> b[i];
		}
		
		for(int i=2;i<N-2;i++){
			
			int mx = max( max(b[i-2],b[i-1]), max(b[i+1],b[i+2]));
			
			if( b[i] > mx){
				ans += (b[i]-mx);
			}
			
		}
		

		cout << "#" << t << " " << ans << endl;
		
	}
	

	return 0;
}