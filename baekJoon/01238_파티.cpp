#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 1001;
const int INF = INT_MAX;
vector<pair<int,int>>adj[MX];
int come[MX];
int dist[MX];
int ans;
int N,M,X;

int dijkstra(int st, int en){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> >ppq;
    fill(come,come+N+1,INF);
    come[st] = 0;
    ppq.push({come[st],st});

    while(!ppq.empty()){
        int curCost = ppq.top().first;
        int curNode = ppq.top().second;
        if(curNode == en) return come[en];
        ppq.pop();

        for(int i=0;i<adj[curNode].size();i++){
            int nxCost = adj[curNode][i].first;
            int nxNode = adj[curNode][i].second;

            if(come[nxNode] <= come[curNode]+nxCost) continue;

            come[nxNode] = come[curNode]+nxCost;
            ppq.push({come[nxNode],nxNode});
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N>>M>>X;

    while(M--){
        int a,b,c;
        cin >> a >> b>> c;

        adj[a].push_back({c,b});
    }
    
    for(int i=1;i<=N;i++){
        dist[i] += dijkstra(i,X);
        dist[i] += dijkstra(X,i);
    }

    for(int i=1;i<=N;i++){
        ans = max(ans,dist[i]);
    }
    cout << ans << '\n';
    return 0;
}