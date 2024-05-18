#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;

// 9 14
// 2 1 8 1 3 7 2 6 3

const int MAX = 100001;

int N,S;
int data[MAX];

bool check(int interval){
	int sum=0;
	
	for(int i=0;i<interval;i++){
		sum+=data[i];
	}
	
	if(sum>=S) return true;
	
	for(int i=0;i<N-interval;i++){
		sum = sum - data[i] + data[i+interval];
		if(sum>=S) return true;
	}
	
	return false;
}

int main(){
	
	cin >> N >> S;
	
	for(int i=0;i<N;i++){
		cin >> data[i];
	}
	
	int start = 1;
	int end = N;
	
    if(check(1)){
    	cout << "1\n";
    	return 0;
	}
	if(!check(N)){
		cout << "-1\n";
		return 0;
	}
	while(start+1<end){
		int mid = (start+end)/2;
		
		if(check(mid)) end = mid;
		else start = mid;
		
	}	
	
	cout << end << endl;
	
	return 0;
}