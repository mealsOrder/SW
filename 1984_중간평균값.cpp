#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;


int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		int arr[10] = {0,};
		int sum=0;
		for(int i=0;i<10;i++){
			cin >> arr[i];
			sum+=arr[i];
		}
		
		sort(arr,arr+10);
		
		float ans = (sum-arr[0]-arr[9])/(8.0);

		cout << "#" << t << " " << round(ans) << endl;
		
	}
	

	return 0;
}