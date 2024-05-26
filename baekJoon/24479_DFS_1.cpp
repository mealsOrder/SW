#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int MAX = 100001;
vector<int>v[MAX];
bool visited[MAX];
int ans[MAX];
int N,M,R;
int cnt=0;
void DFS(int x){
    if(visited[x]) return;
    visited[x] = true;
    cnt++;
    ans[x]=cnt;
    for(int i=0;i<v[x].size();i++){
        int nx = v[x][i];

        if(!visited[nx]){
            DFS(nx);
        }
    }
}

int main(){
	
    cin >>N>>M>>R;

    for(int i=1;i<=M;i++){
        int a, b;
        cin >> a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1;i<=N;i++){
        sort(v[i].begin(),v[i].end());
    }
    
    DFS(R);
    for(int i=1;i<=N;i++)cout << ans[i]<<'\n';
	return 0;
}