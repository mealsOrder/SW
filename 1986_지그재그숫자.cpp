#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		int ans=0;
		int N;
		
		cin >> N;
		
		for(int i=1;i<=N;i++){
			if(i%2==0) ans-=i;
			else ans += i;
		}

		cout << "#" << t << " " << ans << endl;
		
	}
	

	return 0;
}