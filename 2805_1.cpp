#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int a[52][52];


int main(){
	
	int T;
	cin >> T;	
	
	
	for(int t=1;t<=T;t++){
		
		int N=0;
		
		cin >> N;
		
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				
				scanf("%1d", &a[i][j]);
			}
		}	
		
		// python ok but c++ err;;;
		int sum = 0;
		int M = N/2;
		int s = N/2;
		int e = N/2;
		
		for(int i=0;i<N;i++){	
			
			for(int j=s;j<e+1;j++){
				
				sum += a[i][j];
				
				if(i<M){
					s-=1;
					e+=1;
				}
				else{
					s+=1;
					e-=1;
				}
				
			}
			
		}
		
		cout << "#" << t << " " << sum << endl;
		
	}
	
	
}