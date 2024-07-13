#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 20005;
const int INF = INT_MAX;

vector<pair<int,int>>adj[MX]; // [출발정점]{비용,도착정점}
int V,E,K;    // 정점번호,간선개수,시작정점
int dist[MX]; // 최단 거리 테이블
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> V>>E>>K;

    while(E--){
        int u,v,w; // from, to, cost
        cin >>u>>v>>w;
        adj[u].push_back({w,v}); // [from]{cost,to}
                                 //  cost = [from].first 
                                 //  to   = [from].second
    }

    fill(dist,dist+V+1,INF);     // 최단거리 테이블을 정점 개수+1 만큼 무한대로 초기화

    // 우선순위큐 : {비용, 정점번호}
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
    
    // 시작 정점의 거리를 0으로 초기화
    dist[K] = 0;
    // 우선 순위 큐에 (거리,시작점)을 추가
    pq.push({dist[K],K});
    while(!pq.empty()){
        int curCost = pq.top().first; // 현재 비용
        int curNode = pq.top().second;// 현재 노드
        pq.pop();

        // 거리가 dist에 있는 값과 다를 경우 넘어감
        // 넘어가는 이유 : 중복 정점 방문을 방지하기 위해
        //      1. dist[curNode] 는 현재 정점 curNode 까지의 최단 거리 값
        //      2. curCost 는 우선순위 큐에서 꺼낸 현재 정점까지의 거리 값
        //      3. dist[curNode] 와 curCost 가 다르다면, 이미 더 짧은 경로로 curNode 에 도달했다는 의미
        //      4. 이미 최단거리이므로 건너 뛰고 다음 정점 처리로 넘어감
        if(dist[curNode] != curCost) continue;

        for(int i=0;i<adj[curNode].size();i++){
            int nxCost = adj[curNode][i].first; // 다음 비용
            int nxNode = adj[curNode][i].second;// 다음 노드

            // 다음노드의 거리가 현재 노드의 거리와 다음 비용의 합보다 작거나 같으면
            // 이미 최단거리 >> 넘어가자
            if(dist[nxNode] <= dist[curNode] + nxCost) continue;

            // 현재 노드를 거쳐서 nxNode로 가는 것이 더 작은 값을 가질 경우 거리 갱신
            dist[nxNode] = dist[curNode] + nxCost;

            // 갱신된 dist[nxNode] 와 nxNode를 우선 순위 큐에 추가
            pq.push({dist[nxNode],nxNode});
        }
    }
    // 정점 1부터 V까지 순회하며 각 정점까지의 최단 거리를 출력
    for(int i=1;i<=V;i++){
        // dist 값이 무한대 인 경우, 해당 정점까지의 경로가 존재하지 않으므로 INF
        if(dist[i] == INF)cout << "INF\n";

        // 그 외의 경우 최단 거리 값을 출력
        else cout << dist[i] << '\n';
    }

    return 0;
}