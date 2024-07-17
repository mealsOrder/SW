#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 20005;
const int INF = INT_MAX;
vector<pair<int,int>>adj[MX]; // adj[시작노드]{거리,도착노드};
int V,E,K;
int dist[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> V>>E>>K;
    while(E--){
        int u,v,w;
        cin >> u>>v>>w;

        adj[u].push_back({w,v});
    }

    fill(dist,dist+V+1,INF);
    // {거리,시작점}
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;

    dist[K] = 0;
    pq.push({dist[K],K});
    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if(dist[curNode] != curCost)continue;

        for(int i=0;i<adj[curNode].size();i++){
            int nxCost = adj[curNode][i].first; // 다음 비용
            int nxNode = adj[curNode][i].second;// 다음 노드

            if(dist[nxNode] <= dist[curNode]+nxCost) continue;

            dist[nxNode] = dist[curNode]+nxCost;
            pq.push({dist[nxNode],nxNode});
        }
    }

    for(int i=1;i<=V;i++){
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    return 0;
}