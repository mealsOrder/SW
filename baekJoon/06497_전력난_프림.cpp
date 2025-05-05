#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
const int MX = 200001;

int M,N;
vector<pair<int,int>>g[MX]; // g[from] = {cost,to}
bool vis[MX];

int prim(){
    memset(vis,false,sizeof(vis));

    priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> >pq;
    pq.push({0,0}); // {cost,start_node}

    int total = 0;
    int cnt = 0;

    while(!pq.empty() && cnt<M){
        int cost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if(vis[curNode]) continue;

        vis[curNode] = true;
        total+=cost;
        cnt++;

        for(int i=0;i<g[curNode].size();i++){
            int nxCost = g[curNode][i].first;
            int nxNode = g[curNode][i].second;

            if(!vis[nxNode]){
                pq.push({nxCost,nxNode});
            }
        }
    }
    return total;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(true){
        cin >> M >> N;
        if(M == 0 && N == 0) break;

        int totolCost = 0;

        for(int i=0;i<M;i++) g[i].clear();

        for(int i=0;i<N;i++){
            int a,b,c;
            cin >> a >> b >>c;
            totolCost+=c;
            g[a].push_back({c,b});
            g[b].push_back({c,a});
        }
        int minCost = prim();
        //cout << totolCost << '\n';
        //cout << minCost << '\n';
        cout << totolCost - minCost << '\n';
    }
    return 0;
}