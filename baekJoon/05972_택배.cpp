#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 50001;
const int INF = INT_MAX;
int N,M;
int dist[MX];
vector<pair<int,int>>adj[MX]; // [출]{비용,도착}

int main(){
    cin >> N >> M;

    while(M--){
        int a,b,c;
        cin >> a >> b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a}); // 양방향 인가 단방향인가 체크 잘하기!
    }

    fill(dist,dist+N+1,INF);
    dist[1] = 0;
    // {비용,노드}
    priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>  > pq;
    pq.push({dist[1],1});

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

    cout << dist[N];
	return 0;
}