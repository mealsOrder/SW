#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;






int main(){
	

    
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		int N;
		int ans = 0;
		cin >> N;
		
		ans = N / 3 ;
		
		
		

		cout << "#" << t << " " << ans << endl;
		
	}
	

	return 0;
}