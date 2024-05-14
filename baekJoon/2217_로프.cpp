#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int MAX = 100001;

long long int rope[MAX];
long long int ans;

int main(){
    
	int T;
	
	cin >> T;
	
	
	for(int i=0;i<T;i++){
		cin >> rope[i];
	}
	
	sort(rope,rope+T);
	
	for(int i=0;i<T;i++){
		ans = max(ans, (T-i)*rope[i] );
	}
	
	cout << ans;
	
	return 0;
}