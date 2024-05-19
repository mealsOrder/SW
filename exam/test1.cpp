#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int MAX = 10001;

int num[MAX];
int res[MAX];


int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		
		int N,K,cnt=0,ans=0;
		
		memset(num,0,sizeof(num));
		memset(res,0,sizeof(res));
		cin >> N>>K;
		for(int i=0;i<N;i++){
			cin >> num[i];
		}
		
		sort(num , num+N );
		
		for(int i=0;i<N;i++){
			//cout << num[i] << " ";
			for(int j=0;j<N;j++){
				
				res[cnt] = num[i] + num[j];
				cnt++;
			}
				
		}
		
		cout << "#" << t << " " << res[K-1] << endl;
		
		
	}	
	
	return 0;
}