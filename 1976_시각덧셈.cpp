#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int main(){
	

    
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		int H=0,M=0;
		int A,B,C,D;
		
		cin >> A >> B>>C>>D;
		
		H=A+C;
		M=B+D;
		
		
		if(M>=60){
			H+=1;
			M=M-60;
			
		}
		if(H>12) H=H-12;

		cout << "#" << t << " " << H << " " << M << endl;
		
	}
	

	return 0;
}