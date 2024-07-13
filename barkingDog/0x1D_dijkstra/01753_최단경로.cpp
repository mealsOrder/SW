#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int INF = INT_MAX;
const int MX = 20005;
int V,E,S;

// adj[i].first : 비용, adj[i].second : 정점번호
vector<pair<int,int>>adj[MX];
int dist[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> V >> E >> S;
    fill(dist,dist+V+1,INF);

    while(E--){
        int u,v,w; //from,to,cost
        cin >> u>>v>>w;
        adj[u].push_back({w,v});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>> > pq;
    dist[S] = 0;
    pq.push({dist[S],S}); // 우선 순위 큐에 (거리,시작점) 추가
    
    while(!pq.empty()){
        int curX = pq.top().first; // 비용
        int curY = pq.top().second; // 정점 번호
        pq.pop();

        // 거리가 dist에 있는 값과 다를 경우 넘어감
        if(dist[curY] != curX) continue;

        for(int i=0;i<adj[curY].size();i++){
            int nx = adj[curY][i].first; // 다음 비용
            int ny = adj[curY][i].second;// 다음 정점
            if(dist[ny] <= dist[curY] + nx) continue;

            dist[ny] = dist[curY] + nx;
            pq.push({dist[ny],ny});
        }
    }

    for(int i=1;i<=V;i++){
        if(dist[i] == INF)cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    return 0;
}