#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int MX = 10005;
int N;
int a[MX];  // 각마을의 인구수
int d1[MX]; // d1[x] : x마을이 우수 마을일때 최대 인구수 합
int d2[MX]; // d2[x] : x마을이 우수 마을이 아닐때 최대 인구 합

vector<int>adj[MX];

void dfs(int cur,int par){
    d1[cur] = a[cur]; // 현재 마을을 우수 마을로 선택한 경우 -> 인구수 포함
    d2[cur] = 0;      // 현재 마을을 선택하지 않은 경우 -> 초기화

    for(int i=0;i<adj[cur].size();i++){
        int nx = adj[cur][i];
        if(par == nx)continue; // 부모 노드로의 역방향 탐색 방지
        dfs(nx,cur);
        d1[cur] += d2[nx];              // 현재 마을을 선택햇으므로 자식은 선택 못함
        d2[cur] += max(d1[nx],d2[nx]);  // 현재 마을을 선택하지 않았으므로 자식은 선택 or 미선택 중 최대
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;

    for(int i=1;i<=N;i++)cin >> a[i];

    for(int i=0;i<N-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);

    cout << max(d1[1],d2[1]);
    return 0;
}