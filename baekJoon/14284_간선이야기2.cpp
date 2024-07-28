#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 5001;
const int INF = INT_MAX;
int N,M,S,E;
int dist[MX];
vector<pair<int,int>>adj[MX]; // [출]{비용,도착}

int djikstra(int s,int e ){
    dist[S] = 0;
    // {비용,노드}
    priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>  > pq;
    pq.push({dist[S],S});

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if(dist[curNode] != curCost) continue;

        for(int i=0;i<adj[curNode].size();i++){
            int nxCost = adj[curNode][i].first;
            int nxNode = adj[curNode][i].second;

            if(dist[nxNode] <= dist[curNode]+nxCost) continue;
            dist[nxNode] = dist[curNode]+nxCost;
            pq.push({dist[nxNode],nxNode});
        }

    }

    return dist[E];
}

int main(){
    int ans = 0;
    
    cin >> N >> M;

    while(M--){
        int a,b,c;
        cin >> a >> b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a}); // 무방향 그래프!!! 문제좀 읽어라
    }
    cin >> S >> E;
    fill(dist,dist+N+1,INF);

    ans = djikstra(S,E);
    cout << ans << '\n';
	return 0;
}