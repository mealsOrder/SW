#include<iostream>
#include<vector>
#include<algorithm>


int a[1000001];
long long ans;

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
		ans=0;
		for(int i=N;i>=0;i--){
			if(a[i]>mx){
				mx=a[i];
			}
				
			ans+=(mx-a[i]);
				
		}	

		cout << "#" << t << " " << ans << endl;
		
	}
	


}