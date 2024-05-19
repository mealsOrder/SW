#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>

using namespace std;
const int MAX = 101;

vector<int>v[MAX];
bool visited[MAX];

int BFS(int x){
	queue<int>q;
	visited[x] = true;
	q.push(x);
	
	while(!q.empty()){
		
		int cur = q.front();
		q.pop();
		
		if(cur == 99) return 1;
		
		for(int i=0;i<v[cur].size();i++){
			int nx = v[cur][i];
			
			if(!visited[nx]){
				visited[nx] = true;
				q.push(nx);
			}
			
		}
		
	}
	return 0;
}

int main(){
	
	for(int t=1;t<=10;t++){
		
		for(int i=0;i<MAX;i++){
			visited[i]=false;
			v[i].clear();
		}
		
		int num,E;
		cin >> num >> E;
		
		for(int i=0;i<E;i++){
			int a, b;
			cin >> a>>b;
			
			v[a].push_back(b);
			
		}
		
		int ans = BFS(0);
		
		cout << "#" << t << " " << ans << endl;
	}
	
	return 0;
}