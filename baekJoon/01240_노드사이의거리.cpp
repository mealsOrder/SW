#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MX = 1001;
const int INF = 987987987;
vector<pair<int,int>>v[MX];
int N,M;
int dist[MX];
void dijkstra(int s,int e){
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
    fill(dist,dist+N+1,INF);
    dist[s] = 0;
    pq.push({dist[s],s});
    while(!pq.empty()){
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if( dist[curNode] != curDist) continue;
        for(int i=0;i<v[curNode].size();i++){
            int nxDist = v[curNode][i].first;
            int nxNode = v[curNode][i].second;

            if(dist[nxNode] > dist[curNode] + nxDist){
                dist[nxNode] = dist[curNode] + nxDist;
                pq.push({dist[nxNode],nxNode});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=0;i<N-1;i++){
        int a,b,c;
        cin >> a >> b>>c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }

    for(int i=0;i<M;i++){
        int s,e;
        cin >> s >> e;
        dijkstra(s,e);
        cout << dist[e] << '\n';
    }

    return 0;
}