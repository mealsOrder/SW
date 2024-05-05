#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;




int main(){
	
	int T,ans=0;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		int P,Q,R,S,W;
		
		cin >> P>>Q>>R>>S>>W;
		
		int A=P*W;
		int B=0;
		if(W<=R){
			B = Q;
		}
		else{
			B = Q+(W-R)*S;
		}
		
		ans = min(A,B);

		cout << "#" << t << " " << ans << endl;
		
	}
	

	return 0;
}