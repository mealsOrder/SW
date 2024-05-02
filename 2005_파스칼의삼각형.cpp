#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int a[11][11];

int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		int N;
		cin >> N;
		
		// init
		for(int i=0;i<N;i++){
			a[i][0] = 1;
			a[i][i] = 1;
		}
		
		for(int i=2;i<N;i++){
			for(int j=1;j<i;j++){
				a[i][j] = a[i-1][j-1] + a[i-1][j];
			}
		}


		cout << "#" << t << endl;;
		for(int i=0;i<N;i++){
			for(int j=0;j<=i;j++){
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		
	}
	


}