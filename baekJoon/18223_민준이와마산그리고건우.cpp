#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MX = 5001;
const int INF = 987987987;
int V,E,P;
vector<pair<int,int>>v[MX] ;
int dist[MX];

int dijkstra(int s,int e){
    fill(dist,dist + MX,INF);
    priority_queue< pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>> >pq;
    dist[s] = 0;
    pq.push({dist[s],s});
    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if(dist[curNode] != curCost) continue;

        for(int i=0;i<v[curNode].size();i++){
            int nxCost = v[curNode][i].first;
            int nxNode = v[curNode][i].second;
            if(dist[nxNode] > dist[curNode] + nxCost){
                dist[nxNode] = dist[curNode]+nxCost;
                pq.push({dist[nxNode],nxNode});
            }
        }
    }

    return dist[e];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> V >> E >> P;

    for(int i=0;i<E;i++){
        int a,b,c;
        cin >> a>> b>> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    int st = dijkstra(1,P);
    int mid = dijkstra(P,V);
    int tot = dijkstra(1,V);

    if(st+mid <= tot){
        cout << "SAVE HIM";
    }
    else cout << "GOOD BYE";
    return 0;
}