#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int MAX = 10001;

vector<int>v[MAX];
queue<int>q;
bool visited[MAX];
bool check[MAX];

int N,M,V;

// solving Time : 20 min

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

int main(){
	
	cin >> N >> M >> V;
	
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}
	// v num sort
	for(int i=1;i<=N;i++){
		sort(v[i].begin(),v[i].end());
	}
	DFS(V);
	cout << endl;
	BFS(V);
	
	
	
	return 0;
}