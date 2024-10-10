#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MX = 10'001;
const int INF = 987987987;
int N;
vector<pair<int,int>>v[MX];
int dist[MX];
int ans;


int BFS(int x,int y){
    fill(dist,dist+N+1,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    dist[x] = 0;
    pq.push({dist[x],x});

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if(curNode == y) return dist[y];

        for(int i=0;i<v[curNode].size();i++){
            int nxCost = v[curNode][i].second;
            int nxNode = v[curNode][i].first;

            if(dist[nxNode] > dist[curNode]+nxCost){
                dist[nxNode] = dist[curNode]+nxCost;
                pq.push({dist[nxNode],nxNode});
            }
        }
    }

    return INF;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    int T = N -1;
    while(T--){
        int a,b,c;
        cin >> a >> b>> c;

        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i == j)continue;
            int k = BFS(i,j);
            if(k != INF) ans = max(ans,k);
        }
    }

    cout << ans << '\n';

    return 0;
}