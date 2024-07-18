#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 101;
const int INF = INT_MAX;
vector<pair<int,int>>adj[MX]; // [출발]{비용,도착}
int N,M;
int dist[MX];

int dijkstra(int start,int end){
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
    dist[start] = 0;
    pq.push({dist[start],start});

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        if(curNode == end) return dist[end];
        pq.pop();

        if(dist[curNode] != curCost) continue;

        for(int i=0;i<adj[curNode].size();i++){
            int nxCost = adj[curNode][i].first;
            int nxNode = adj[curNode][i].second;

            nxCost += curCost;

            if(dist[nxNode] <= nxCost) continue;

            dist[nxNode] = nxCost;
            pq.push({dist[nxNode],nxNode});         
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N>>M;

    while(M--){
        int from,to,cost;
        cin >> from >> to>> cost;

        adj[from].push_back({cost,to});
    }

    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            fill(dist,dist+N+1,INF);
            int ans = dijkstra(i,j);
            cout << ans << " ";
        }
        cout << '\n';
    }

    return 0;
}