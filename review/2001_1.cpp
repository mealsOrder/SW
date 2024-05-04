#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// solving time : 25min


int map[20][20];

int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		
		int N,M;
		
		cin >> N >> M;
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin >> map[i][j] ;
			}
		}
		
		int ans = 0;
		for(int i=0;i<N-M+1;i++){
			for(int j=0;j<N-M+1;j++){
				
				int mx = 0;
				
				for(int si=i;si<i+M;si++){
					for(int sj=j;sj<j+M;sj++){
						mx+=map[si][sj];
						
					}
				}
				if(ans < mx){
					ans = mx;
				}
			}
		}

		cout << "#" << t << " " << ans << endl;
		
	}
	

	return 0;
}