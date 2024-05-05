#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		int N, A, B;
		
		cin >> N >> A >> B;
		
		long long int min_ans = 9876543210;
		long long int R,C;
		
		for(R=1;R<=sqrt(N);R++){
			
			long long int maxC = N/R;
			
			for(C=1;C<=maxC;C++){
				long long int ans = A*abs(R-C)+B*(N-R*C);
				
				if(min_ans>ans){
					min_ans = ans;
				}
			}
			
			
		}
		

		cout << "#" << t << " " << min_ans << endl;
		
	}
	

	return 0;
}