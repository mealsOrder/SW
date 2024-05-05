#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 100001;

vector<int>v[MAX];
bool visited[MAX];
bool check[MAX];
queue <int> q;

int N,M;

void DFS(int x){
	visited[x] = true;
	cout << x << " ";
	
	for(int i=0;i<v[x].size();i++){
		int next = v[x][i];
		
		if(visited[next] == false){
			DFS(next);
		}
	}
	
}

void BFS(int x){
	check[x] = true;
	q.push(x);
	
	while(!q.empty()){
		
		int current = q.front();
		q.pop();
		cout << current << " ";
		
		for(int i=0;i<v[current].size();i++){
			int next = v[current][i];
			
			if(check[next] == false){
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
  
  cin >> N >> M;
  
  for(int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    
    v[a].push_back(b);
    v[b].push_back(a);
    
  }
  
  for(int i=0;i<M;i++){
  	sort(v[i].begin(),v[i].end());
  }
  
  DFS(0);
  cout << endl;
  BFS(0);
    
  return 0;
}