#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int a[10][10];


int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cin >> a[i][j];
			}
		}
		
		//row
		bool flag = true;
		bool chk[10];
		
		
		for(int i=0;i<9;i++){
			fill_n(chk,10,0);
			for(int j=0;j<9;j++){
				int num = a[i][j];
				// num exist
				if( chk[num] ){
					flag = false;
					break;
				}
				else{
					chk[num] = true;
				}
			}
		}

		//col
		
		for(int i=0;i<9;i++){
			fill_n(chk,10,0);
			for(int j=0;j<9;j++){
				int num = a[j][i];
				// if num exists, change flag false and break;
				if( chk[num] ){
					flag = false;
					break;
				}
				else{
					chk[num] = true;
				}
			}
		}			

		//box
		
		
		for(int i=0;i<9;i+=3){
			for(int j=0;j<9;j+=3){
				
				fill_n(chk,10,0);
				for(int si=0;si<3;si++){
					for(int sj=0;sj<3;sj++){
						int num = a[i+si][j+sj];
						if(chk[num]){
							flag = false;
							break;
						}
						else{
							chk[num] =true;
						}
					}
				}
			}
		}	

		if( flag ) 		cout << "#" << t << " 1" << endl;
		else 			cout << "#" << t << " 0" << endl;
		
	}
	


}