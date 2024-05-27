#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
const int MX = 100001;
vector<int>v[MX];
bool visited[MX];
int ans[MX];
void DFS(int x){
    if(visited[x])return;
    visited[x]=true;

    for(int i=0;i<v[x].size();i++){
        int nx = v[x][i]; // 4 // 6
        
        if(!visited[nx]){
            ans[nx] = x;    
            DFS(nx);
        }
        
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i=2;i<=N;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1);

    for(int i=2;i<=N;i++) cout << ans[i] << "\n";
	return 0;
}