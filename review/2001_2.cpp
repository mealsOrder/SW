#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//solving Time : 15 min

const int MAX = 20;

int map[MAX][MAX];

int N,M;
int ans;
void init(){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			map[i][j] = 0;
		}
	}
}

int main(){
	

    
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		ans= 0 ;
		init();
		cin >> N >>M;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin >> map[i][j];
			}			
		}
		
		for(int i=0;i<=N-M;i++){
			
			for(int j=0;j<=N-M;j++){
				
				int mx = 0;
				for(int si=i;si<i+M;si++){
					
					for(int sj=j;sj<j+M;sj++){
						mx += map[si][sj];
						if(mx > ans){
							ans = mx;
						}
					}
				}
				
				
			}			
		}

		cout << "#" << t << " " << ans << endl;
		
	}
	

	return 0;
}