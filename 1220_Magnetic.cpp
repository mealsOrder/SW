#include<iostream>
#include<cstring>

using namespace std;

const int MAX = 101;

int map[MAX][MAX];


int main(){
	
	for(int t=1;t<=10;t++){
		
		int T,ans=0;
		cin >> T;
		
		
		for(int j=0;j<100;j++){
			for(int i=0;i<100;i++){
				cin >> map[j][i];
			}
		}
		
		
		for(int j=0;j<100;j++){
			bool NO=false;
			bool SO=false;
			for(int i=0;i<100;i++){
				if(map[i][j]==1) NO=true;
				else if(map[i][j]==2){
					if(NO && !SO){
						ans++;
						
						NO=false;
						SO=false;
					}
				}
			}
		}		
		
		cout << "#" << t <<" "<<ans<<'\n';		
	}	
	
	return 0;
}