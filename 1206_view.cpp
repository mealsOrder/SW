#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int arr[1001];

void init(int n){
	for(int i=0;i<n;i++){
		arr[i] = 0;
	}
}

int main(){
	int T=10;
	
	for(int t=1;t<=T;t++){
		int N;
		
		
		cin >> N;
		for(int i=0;i<N;i++){
			cin >> arr[i];
		}
		
		// left 0 right	
		
		int ans = 0;
		for(int x=2;x<N-2;x++){
			int large = max( max(arr[x-2],arr[x-1] ), max(arr[x+1],arr[x+2]) ); 
			
			if( large < arr[x]){
				ans += (arr[x] - large );
			}
		}
		
		cout << "#" << t << " " << ans << endl;
	}



}