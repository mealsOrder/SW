#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 1001;
const int INF = INT_MAX;
int N,M,S,E;
vector<int>v;
vector<pair<int,int>>adj[MX];
int dist[MX];
int pre[MX];
int cnt = 0;
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
    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
    
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

            if(dist[nxNode] <= dist[curNode]+nxCost) continue;            
            dist[nxNode] = dist[curNode] + nxCost;
            pq.push({dist[nxNode],nxNode});
            pre[nxNode] = curNode;        
        }
    }

    cout << dist[E] << '\n';
    vector<int>path;
    int cur = E;
    while(cur != S){
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    reverse(path.begin(),path.end());
    cout << path.size() << '\n';
    for(auto x : path) cout << x << ' ';
    return 0;
}