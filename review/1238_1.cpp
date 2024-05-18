#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 101;

vector<int>v[MAX];
int dist[MAX];

void BFS(int x){
	queue<int>q;
	q.push(x);
	dist[x] = 1;
	
	while(!q.empty()){
		int curX = q.front();
		q.pop();
		
		for(int i=0;i<v[curX].size();i++){
			int nx = v[curX][i];
			
			if(dist[nx]==0){
				dist[nx] = dist[curX] + 1;
				q.push(nx);
			}
			
		}
		
	}
	
}


int main(){
	
	
	int T=10;
	
	for(int t=1;t<=T;t++){
		
		int len,si;
		
		cin >> len >> si;
		
		for(int i=0;i<MAX;i++){
			v[i].clear();
			dist[i]=0;
		}
		
		for(int i=0;i<len/2;i++){
			int from,to;
			cin >> from >> to;
			
			v[from].push_back(to);
			
		}
		
		BFS(si);
		
		int ans = si;
		
		for(int i=1;i<MAX;i++){
			if(dist[i] >= dist[ans] ) ans = i;
		}
		
		cout << "#" << t << " " << ans << '\n';
	}
	
	
	
	
	
	
	return 0;
}