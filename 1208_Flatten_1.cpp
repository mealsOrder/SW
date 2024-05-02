#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int D;
int H[101];
int ans=0;	


int main(){
	
	int T=10;
	
	//cin >> T;
	
	
	
	for(int t=1;t<=T;t++){
		
		cin >> D;
		
		for(int i=0;i<100;i++){
			cin >> H[i];
		}
		
			
		
		
		while(true){

			int mx=0;
			int mxi=0;
			int mn=101;
			int mni=0;
			for(int i=0;i<100;i++){
				if(mx<H[i]){
					mx=H[i];
					mxi=i;
				}
				if(mn>H[i]){
					mn=H[i];
					mni=i;
				}
			}
			
			H[mxi]--;
			H[mni]++;
			if(D==0){
				ans = mx-mn;
				break;
			}
			D--;
		}
		
		
		cout << "#" << t << " " << ans << endl;
		
	}
	


}