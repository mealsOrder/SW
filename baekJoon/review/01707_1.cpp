#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

// solving Time : 29 min;

const int MAX = 20001;
const int RED = 1;
const int BLUE = 2;

vector<int>v[MAX];
int visited[MAX];


void DFS(int start, int color){
	
	visited[start] = color;
	
	for(int i=0;i<v[start].size();i++){
		int next = v[start][i];
		
		if(!visited[next]){
			
			DFS(next,3-color);
		}
		
	}
	
	
	
}

int main(){
	
	int K,V,E;

	cin >> K;
	for(int t=0;t<K;t++){
		
		cin >> V >> E;
		
		// init
		for(int i=0;i<=V;i++){
			v[i].clear();
		}
		
		memset(visited,0,sizeof(visited));
		
		for(int i=0;i<E;i++){
			int a,b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
			
		}
		
		
		for(int i=1;i<=V;i++){
			if( visited[i] == 0){
				DFS(i,RED);
			}
		}
		
		bool isBigraph = true;
		
		for(int i=1;i<=V;i++){
			for(int j=0;j<v[i].size();j++){
				int next = v[i][j];
				
				if(visited[i] == visited[next]){
					isBigraph = false;
					break;
				}
				
			}
			if(!isBigraph) break;
		}
		
		
		if(isBigraph) cout << "YES\n";
		else cout << "NO\n";
		
	}    
	

	return 0;
}