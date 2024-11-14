#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
const int MX = 1001;
const int INF = 987987987;
vector<pair<int,int>>v[MX];
int N,V,E,A,B;
int house[MX];
int dist[MX];

int ans_A,ans_B,ans;
int dijkstra(int s, int e){
    priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int > > > pq;
    fill(dist,dist+V+1,INF);
    dist[s] = 0;
    pq.push({dist[s],s});

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if( curNode == e && dist[e]!=INF) return dist[e];

        if( dist[curNode] != curCost)continue;

        for(int i=0;i<v[curNode].size();i++){
            int nxCost = v[curNode][i].first;
            int nxNode = v[curNode][i].second;

            if(dist[nxNode] > dist[curNode] + nxCost){
                dist[nxNode] = dist[curNode] + nxCost;
                pq.push({dist[nxNode],nxNode});
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    cin >> N >> V >> E >> A >> B;

    for(int i=0;i<N;i++) cin >> house[i]; // 시작 노드

    // 도로 간선 연결
    while(E--){
        int a,b,c;
        cin >> a >> b >> c;

        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    
    for(int i=0;i<N;i++){
        ans_A = dijkstra(house[i],A);
        ans_B = dijkstra(house[i],B);
        ans += (ans_A + ans_B);
    }
    cout << ans << '\n';
    return 0;
}