#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<tuple>
#include<cstring>
using namespace std;
using ll = long long;
const int KMX = 20;
const int NMX = 10'000;
const int INF = 1e9;
int N,M,K;
ll dist[KMX+2][NMX+2];
vector<tuple<ll,int,int>>adj[NMX+2];  // [from]{cost,nxtK,to}
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);
    
    memset(dist,0x3f,sizeof(dist));

    cin >> N >> M >> K;

    for(int i=0;i<M;i++){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({c,0,b});
        adj[b].push_back({c,0,a});
        adj[a].push_back({0,1,b});
        adj[b].push_back({0,1,a});
    }

    priority_queue<tuple<ll,int,int>,
                vector<tuple<ll,int,int>>,
                greater<tuple<ll,int,int>> >pq; 
    
    for(int i=0;i<=K;i++) dist[i][1] = 0;
    pq.push({0,0,1});

    while(!pq.empty()){
        auto [curCost,curK,curNode] = pq.top();
        pq.pop();
        if(dist[curK][curNode] != curCost) continue;
        for(auto [nxCost, nxK,nxNode] : adj[curNode]){
            nxCost += curCost;
            nxK += curK;
            if(nxCost >= dist[nxK][nxNode]) continue;
            if(nxK > K) continue;
            dist[nxK][nxNode] = nxCost;
            pq.push({nxCost,nxK,nxNode});
        }
    }
    ll ans = LLONG_MAX;
    for(int i=0;i<=K;i++){
        ans = min(ans,dist[i][N]);
    }
    cout << ans;
    return 0;
}