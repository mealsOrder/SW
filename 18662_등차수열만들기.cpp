#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		double A,B,C;
		
		cin >> A >> B >> C;
		
		double ans = abs(((B-A) - (C-B))/2 );
		
		cout << fixed;
		cout.precision(1);

		cout << "#" << t << " " << ans << endl;
		
	}
	

	return 0;
}