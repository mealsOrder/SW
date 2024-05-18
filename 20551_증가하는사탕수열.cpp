#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main(){
    
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		int A,B,C, ans=0;
		bool flag = false;
		
		cin >> A>>B>>C;
		
		if(B==1 || C==1) flag = true;
		
		while(B>=C){
			B--;
			ans++;
		}
		while(A>=B){
			A--;
			ans++;
		}
		

		cout << "#" << t << " ";
		if(flag) cout << "-1\n";
		else cout << ans << endl; 
		
	}
	

	return 0;
}