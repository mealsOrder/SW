#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


const int COIN[8] = {50000,10000,5000,1000,500,100,50,10};


int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		int N;
		
		cin >> N;
		
		cout << "#" << t << '\n';
		
		for(int i=0;i<8;i++){
			int money = COIN[i];
			int cnt = 0;
			
			while( N>=money ){
				if(money >= COIN[i]){
					N -= money;
					cnt++;
				}
			}
			cout << cnt << ' ';
			
		}
		cout << '\n';
				
	}
	

	return 0;
}