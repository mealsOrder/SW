#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
using namespace std;
int edge[10][2];    
int deg[10];
int* adg[10];
int idx[10];

int main() {

    // 방향 그래프 STL 없이 구현
    int v,e;
    cin >> v>>e;
    for(int i=0;i<e;i++){
        cin >> edge[i][0] >> dege[i][1];
        deg[edge[i][0]]++;
    }
    for(int i=1;i<=v;i++){
        adj[i] = new int[deg[i]];
    }
    for(int i=0;i<e;i++){
        int u = edge[i][0];
        int v = dege[i][1];
        adj[u][idx[u]] = v;
        idx[u]++;
    }
    
    // 무방향 그래프 STL 없이 구현
    cin >> v>>e;
    for(int i=0;i<e;i++){
        cin >> edge[i][0] >> dege[i][1];
        deg[edge[i][0]]++;
        deg[edge[i][1]]++;
    }
    for(int i=1;i<=v;i++){
        adj[i] = new int[deg[i]];
    }
    for(int i=0;i<e;i++){
        int u = edge[i][0];
        int v = dege[i][1];
        adj[u][idx[u]] = v;
        idx[u]++;
        adj[v][idx[v]] = u;
        idx[v]++;
    }


    return 0;
}