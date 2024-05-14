#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;



int main(){
	

    
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		int L,U,X;
		int ans=0;
		cin >> L >>U>>X;
		
		if(X > U){
			ans = -1;
		}
		else if(X<=U && X>=L){
			ans = 0;
		}
		else{
			ans = L-X;
		}
		
		

		cout << "#" << t << " " << ans << endl;
		
	}
	

	return 0;
}