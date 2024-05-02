#include<iostream>
#include<vector>
#include<algorithm>


int a[1000001];
typedef long long ll;

using namespace std;


int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		int N;
		cin >> N;
		
		for(int i=0;i<N;i++){
			cin >> a[i];
		}
		
		int mx=0;
		ll ans=0;
		for(int i=N-1;i>=0;i--){
			if(a[i]>mx){
				mx=a[i];
				
			}
			
			ans+=(mx-a[i]);
			
		}
		

		cout << "#" << t << " " << ans << endl;
		
	}
	


}