#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;



int main(){
	

    
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		int N;
		cin >> N;
		

		cout << "#" << t << " ";
		for(int i=1;i<=N;i++){
			cout << "1/" << N << " ";
		}
		cout << endl;
		
	}
	

	return 0;
}