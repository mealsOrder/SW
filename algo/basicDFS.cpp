#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// input
// 9 12
// 1 2
// 1 3
// 2 3
// 2 4
// 2 6
// 3 7
// 4 5
// 4 7
// 4 8
// 5 6
// 7 8
// 8 9

// out
// 1 2 3 7 4 5 6 8 9 

const int MAX = 100;

vector<int>v[MAX];
bool visited[MAX];

int N,M;

void DFS(int x){
	visited[x] = true;
	
	cout << x << " ";
	
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
	
	return 0;
}