#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 1001;
const int INF = INT_MAX;
int N,M,S,E;
vector<pair<int,int>>adj[MX]; // [출발]{비용,도착}
int dist[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;

    while(M--){
        int a,b,c;
        cin >> a>>b>>c;

        adj[a].push_back({c,b});
    }
    cin >> S >> E;
    fill(dist,dist+N+1,INF);

    // {비용,노드}
    priority_queue< pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> >pq;
    dist[S] = 0;
    pq.push({dist[S],S});

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if(dist[curNode] != curCost)continue;

        for(int i=0;i<adj[curNode].size();i++){
            int nxCost = adj[curNode][i].first;
            int nxNode = adj[curNode][i].second;

            nxCost += curCost;
            
            if( dist[nxNode] <= nxCost) continue;

            dist[nxNode] = nxCost;
            pq.push({dist[nxNode],nxNode});
        }
    }

    cout << dist[E] << '\n';

    return 0;
}