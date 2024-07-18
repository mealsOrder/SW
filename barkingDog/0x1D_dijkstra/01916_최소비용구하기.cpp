#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

const int MX = 1005;
const int INF = INT_MAX;
int dist[MX];
vector<pair<int,int>>adj[MX]; // [시작노드]{비용,도착노드};
int N,M,S,E; // 노드 개수, 간선 개수, 시작노드, 도착노드
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    while(M--){
        int from,to,cost;
        cin >> from >> to >> cost;
        adj[from].push_back({cost,to});// [시작노드]{비용,도착노드};
    }
    cin >> S>>E;
    fill(dist,dist+N+1,INF); // 모든 노드의 최단 거리를 무한대로 초기화
    // {거리,노드}
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
    dist[S] = 0; // 시작 노드의 거리는 0
    pq.push({dist[S],S});

    while(!pq.empty()){
        int curCost = pq.top().first;  // 현재 노드까지의 최단 거리
        int curNode = pq.top().second; // 현재 노드
        pq.pop(); // 현재 노드 꺼내기

        // 현재 노드의 최단 거리가 이미 갱신된 경우 무시
        // 현재 노드의 최단 거리가 현재 비용과 다르면 무시
        if(dist[curNode] != curCost)continue;

        // 현재 노드에서 인접한 노드로 이동
        for(int i=0;i<adj[curNode].size();i++){
            int nxCost = adj[curNode][i].first; // 다음 노드까지의 비용
            int nxNode = adj[curNode][i].second;// 다음 노드

            nxCost += curCost; // 현재 노드까지의 최단 비용 + 다음노드 까지의 비용
            
            // 다음 노드 까지의 최단 거리가 이미 갱신된 경우 무시
            if(dist[nxNode] <= nxCost) continue;
            
            // 다음 노드까지의 최단 거리 갱신
            dist[nxNode] = nxCost;
            pq.push({dist[nxNode],nxNode}); // 다음 노드까지의 최단 거리와, 다음 노드를 큐에 삽입

        }
    }
    cout << dist[E] << '\n';
    return 0;
}