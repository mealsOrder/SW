#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

//[input]
//3                         // tc
//
//
//3 7                       // N = 3, K = 7 #1
//
//
//3 2 3
//
//
//5 6                       // N = 5, K = 6  #2
//
//
//1 2 3 4 5
//
//
//5 10                       // N = 5, K = 10 #3
//
//
//3 2 1 1 3
//
// 
//
//[outPut]
//
//#1 6
//
//
//#2 3
//
//
//#3 4

const int MAX = 10001;

int num[MAX];
int res[MAX];

vector<pair<int,int>>v;

int main(){
	
	int T;
	
	cin >> T;
	
	for(int t=1;t<=T;t++){
		
		
		int N,K,cnt=0,ans=0;
		
		memset(num,0,sizeof(num));
		v.clear();
		cin >> N>>K;
		for(int i=0;i<N;i++){
			cin >> num[i];
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				v.push_back({num[i],num[j]});
			}
				
		}
		
		sort(v.begin(),v.end());
		
		ans = v[K-1].first + v[K-1].second;
		cout << "#" << t << " " << ans << endl;
		
		
	}	
	
	return 0;
}