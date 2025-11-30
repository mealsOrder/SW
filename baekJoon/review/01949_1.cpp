#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int MX = 10001;

vector<int>adj[MX];
int N;
int a[MX];
int d1[MX];
int d2[MX];

void dfs(int x,int parent){
    d1[x] = a[x];
    d2[x] = 0;

    for(int i=0;i<adj[x].size();i++){
        int nx = adj[x][i];
        if(nx == parent) continue;

        dfs(nx,x);
        d1[x] += d2[nx];
        d2[x] += max(d1[nx] ,d2[nx]);
        
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;

    for(int i=1;i<=N;i++)cin >> a[i];

    for(int i=0;i<N-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);

    cout << max(d1[1],d2[1]);
    return 0;
}