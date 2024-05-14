#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;



int main(){
	

    
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		int A,B;
		int ans = 0;
		
		cin >> A >> B;
		
		ans = A+B;
		
		if(ans >= 24){
			ans = A+B - 24; 
		}
		
		
		

		cout << "#" << t << " " << ans << endl;
		
	}
	

	return 0;
}