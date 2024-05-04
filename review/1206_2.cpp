#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


// solving time : 16min

int H[1002];
int N;

int main(){
	
	
	for(int t=1;t<=10;t++){
		cin >> N;
		
		for(int i=0;i<N;i++){
			cin >> H[i];
		}
		
		int mx=0;
		int ans=0;
		for(int i=0;i<N-2;i++){
			mx = max(max(H[i-2],H[i-1]),max(H[i+1],H[i+2]));
			if(mx < H[i]){
				ans += H[i]- mx;
			}
		}
		
		
		
		cout << "#" << t << " " << ans << endl;
	}
	
	
	return 0;
}