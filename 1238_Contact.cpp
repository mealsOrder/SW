#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int MAX = 101;

vector<int>v[MAX];
int deep[MAX];


void BFS(int x){
	queue<int>q;
	q.push(x);
	deep[x] = 1;
	
	while(!q.empty()){
		int curX = q.front();
		q.pop();
		
		for(int i=0;i<v[curX].size();i++){
			int nx = v[curX][i];
			
			if(deep[nx] == 0){
				deep[nx] = deep[curX] + 1;
				q.push(nx);
			}
			
		}
		
	}
	
}

int main(){

	int T=10;
	
	for(int t=1;t<=T;t++){
		
		int len, si;
		
		cin >> len >> si;
		
		for(int i=1;i<MAX;i++){
			v[i].clear();
			deep[i]=0;
		}
		
		for(int i=0;i<len/2 ;i++){
			int from,to;
			cin >> from >> to;
			v[from].push_back(to);
		}
		
		BFS(si);
		
		int ans = si;
		for(int i=1;i<MAX;i++){
			if(deep[i]>=deep[ans]) ans=i;
		}

		cout << "#" << t << " " << ans << endl;
		
	}
	

	return 0;
}