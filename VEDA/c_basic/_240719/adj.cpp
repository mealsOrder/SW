#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
const int MX = 20001;
const int INF = INT_MAX;
int N,M,S,E;
int dist[MX];
vector<pair<int,int>>adj[MX];
int main(){
	cin >> N>>M>>S;
	
	while(M--){
		int a,b,c;
		cin >> a>>b>>c;
		adj[a].push_back({c,b});
	}
	
	fill(dist,dist+N+1,INF);
	dist[S] = 0;
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	pq.push({dist[S],S});
	
	while(!pq.empty()){
		int curCost = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		
		if(dist[curNode] != curCost)continue;
		
		for(int i=0;i<adj[curNode].size();i++){
			int nxCost = adj[curNode][i].first;
			int nxNode = adj[curNode][i].second;
			
			nxCost+=curCost;
			
			if(dist[nxNode] <= nxCost) continue;
			dist[nxNode] = nxCost;
			pq.push({dist[nxNode],nxNode});
		}
	}
	
	for(int i=1;i<=N;i++){
		if(dist[i] == INF)cout << "INF\n";
		else cout << dist[i] << '\n';
	}
	
	
	return 0;
}