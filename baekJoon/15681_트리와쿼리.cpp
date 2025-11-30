#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
using namespace std;

const int MX = 100001;
vector<int>adj[MX];
int subTreeSize[MX];
bool vis[MX];

int dfs(int node){
    vis[node]=true;
    int size = 1;

    for(int i=0;i<adj[node].size();i++){
        int nx = adj[node][i];

        if(!vis[nx]){
            size += dfs(nx);
        }
    }

    return subTreeSize[node] = size;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,R,Q;
    cin >> N >> R >> Q;

    for(int i=0;i<N-1;i++){
        int a,b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(R);
    while(Q--){
        int k;
        cin >> k;
        cout << subTreeSize[k] << '\n';
    }

    return 0;
}
