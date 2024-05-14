#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

queue<int>q;
int main(){
	

    
	int N,K;
	
	cin >> N>>K;
	
	for(int i=1;i<=N;i++){
		q.push(i);		
	}
	
	cout << "<";
	int cnt = 1;
	
	while(!q.empty()){
		
		if(cnt%K == 0){
			int ans = q.front();
			q.pop();
			if(q.empty()){
				cout << ans <<">";
			}
			else{
				cout << ans <<", ";
			}
		}
		else{
			int notA = q.front();
			q.pop();
			q.push(notA);	
		}
		cnt++;
	}
	

	return 0;
}