#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int H[1004];


int main(){
	
	int T=10;
	
	
	
	for(int t=1;t<=T;t++){
		int N;
		cin >> N;
		for(int i=0;i<N;i++){
			cin >> H[i];
		}
		
		int ans=0;
		for(int x=2;x<=N-2;x++){
			int Big = max( max(H[x-2],H[x-1]) , max(H[x+1],H[x+2])  );
		
			if(Big < H[x]){
				ans+= H[x]-Big;
			}
		}
		

		cout << "#" << t << " " << ans << endl;
		
	}
	

	return 0;
}