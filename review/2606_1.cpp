#include<iostream>
#include<algorithm>
#include<vector>

// solving Time : 8 min

using namespace std;

int N,M;

const int MAX = 200;
vector<int>v[MAX];
bool visited[MAX];
int cnt;

void DFS(int x){
	visited[x] = true;
	
	cnt++;
	
	for(int i=0;i<v[x].size();i++){
		int y = v[x][i];
		
		if(visited[y] == false){
			DFS(y);
		}
	}
	
		
}

int main(){
	
		
	cin >> N >> M;
	
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
		
	}
	
	DFS(1);
	
	cout << cnt-1 << endl;
	
	
	return 0;
}