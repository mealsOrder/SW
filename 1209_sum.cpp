#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int a[101][101];
int row[101];
int col[101];


int main(){
	
	
	
	for(int t=1;t<=10;t++){
		
		int T;
	
		cin >> T;
		
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				cin >> a[i][j];
			}
		}	
		
		// init
		int ans=0;
		int cross=0;
		int cross2=0;
		fill_n(row,100,0);
		fill_n(col,100,0);
		
		for(int i=0;i<100;i++){
			cross += a[i][i];
			cross2 += a[i][99-i];
			for(int j=0;j<100;j++){
				row[i]+=a[i][j];
				col[i]+=a[j][i];
								
			}
		}
		
		sort(row,row+100);			
		sort(col,col+100);			
		
		ans = max( max(cross,cross2) , max(row[99], col[99]) );
		
		cout << "#" << t << " " << ans << endl;
		
	}
	
	
}