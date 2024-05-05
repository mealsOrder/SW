#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

// solving Time : 40 min

const int MAX = 20001;
const int RED = 1;
const int BLUE = 2;

vector<int>v[MAX];
int visited[MAX];

void DFS(int x,int color){
	visited[x] = color;
	
	for(int i=0;i<v[x].size();i++){
		int next = v[x][i];
		
		if(visited[next] == 0){
			DFS(next,3-color);
		}
	}
	
}


int main(){
	
	int K,V,E;
	
	cin >> K;
	
	while(K--){
		cin >> V >> E;
		
		// init
		memset(visited,0,sizeof(visited));
		for(int i=1;i<=V;i++){
			v[i].clear();
		}
		
		
		for(int i=0;i<E;i++){
			int a,b;
			cin >> a >> b;
			
			v[a].push_back(b);
			v[b].push_back(a);
			
		}
		
		for(int i=1;i<=V;i++){
			if(visited[i] == 0){
				DFS(i,RED);
			}
		}
		
		int isBigraph = true;
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
		
		if(isBigraph == false) cout << "NO" << endl;
		else cout << "YES" << endl;
		
	}
	
	return 0;
}