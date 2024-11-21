#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
using ll = long long;
const int KMX = 20;
const int NMX = 10001;
const int INF = 1e9;
int N,M,K;
vector<tuple<ll,int,int>> adj[NMX]; // [from]{cost,nxk,to};
ll dist[KMX+2][NMX+2];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

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
    priority_queue< tuple<ll,int,int>,
        vector<tuple<ll,int,int>>,
        greater<tuple<ll,int,int>> >pq;
    
    for(int i=0;i<=K;i++) dist[i][1] = 0;
    pq.push({0,0,1});

    while(!pq.empty()){
        auto [curCost, curK, curNode] = pq.top(); pq.pop();
        if(dist[curK][curNode] != curCost)continue;

        for(auto [nxCost, nxK, nxNode] : adj[curNode]){
            nxCost += curCost;
            nxK += curK;
            if(nxCost >= dist[nxK][nxNode])continue;
            if(nxK>K)continue;
            dist[nxK][nxNode] = nxCost;
            pq.push({nxCost,nxK,nxNode});
        }
    }

    ll ans = 0x3f3f3f3f3f3f3f;
    for(int i=0;i<=K;i++){
        ans=min(ans,dist[i][N]);
    }

    cout << ans << '\n';
    return 0;
}