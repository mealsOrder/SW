#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int a[50][50];
int row[101];
int col[101];


int main(){
	
	int T;
	cin >> T;	
	
	
	for(int t=1;t<=T;t++){
		
		int N;
		
		cin >> N;
		
                
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				
				scanf("%1d", &a[i][j]);
			}
		}	
		
		
		int mid = N/2;
		int sum = 0;
		
		for(int i=0;i<N;i++){	
			if(i<=mid){
				
				for(int j=mid-i;j<=mid+i ;j++){
					sum+=a[i][j];
				}	
			}			
			else{
				
				for(int j=i-mid;j<N-(i-mid) ;j++){
				                  
					sum+=a[i][j];
				}			
			}
		}
		
		cout << "#" << t << " " << sum << endl;
		
	}
	
	
}