#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 100001;
vector<int>v[200001];
int visited[MAX];
int cnt=0;
int N,M,R;

bool compair(int a, int b){
	if(a>b) return true;
	else return false;
}


void DFS(int x){
	if(visited[x]) return;
	
	visited[x] = ++cnt;
	
	for(int i=0;i<v[x].size();i++){
		int next = v[x][i];
		
		if(visited[next] == 0){
			DFS(next);
		}
	}
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	cin >> N >> M >> R;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i=0;i<=N;i++){
		sort(v[i].begin(),v[i].end(),greater<int>());
	}
	
	DFS(R);
	
	for(int i=1;i<=N;i++){
		cout << visited[i] << '\n';
	}
	
	
	return 0;
}

		
