#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int main(){
	
	int N;
	
	cin >> N;
	
	
	
	for(int i=1;i<=N;i++){
		int cnt = 0;
		int num = i;
		
		
		while(num>0){
			if(num%10 == 3 || num%10 == 6 || num%10 == 9){
				cnt++;
			}
			num/=10;
		}
		
		
		if(cnt == 0){
			cout << i << " ";
		}
		else{
			for(int j=0;j<cnt;j++){
				cout << "-";
			}
			cout << " ";
		}
		
	}


}