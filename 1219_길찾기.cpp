#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAX = 101;

vector<int>v[MAX];
bool visited[MAX];


int BFS(int x){
	queue<int>q;
	q.push(x);
	visited[x]=true;
	
	while(!q.empty()){
		int curX = q.front();
		if(curX == 99) return 1;
		q.pop();
		
		for(int i=0;i<v[curX].size();i++){
			int nx = v[curX][i];
			
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
		int T,E;
		
		cin >> T>>E;
		for(int i=0;i<MAX;i++){
			visited[i] = 0;
			v[i].clear();
		}
		for(int i=0;i<E;i++){
			int a,b;
			cin >> a>>b;
			
			v[a].push_back(b);
			
		}
		
		int ans = BFS(0);
		
		cout << "#" << t << " " << ans<<'\n';
	}
	
	return 0;
}