#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int D;
int H[101];


int main(){
	
	int T=10;
	
	//cin >> T;
	
	for(int t=1;t<=T;t++){
		
		cin >> D;
		
		for(int i=0;i<100;i++){
			cin >> H[i];
		}
		
		while(D--){
			sort(H,H+100);
			
			if( H[99]-H[0] <= 1 ){
				
				break;
			
			}
			H[0]++;
			H[99]--;
			
		}	

		sort(H,H+100);
		
		cout << "#" << t << " " << H[99]-H[0] << endl;
		
	}
	
	return 0;

}