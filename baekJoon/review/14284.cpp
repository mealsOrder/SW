#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

const int MX = 5001;
const int INF = INT_MAX;
int N,M,S,E;
vector<pair<int,int>>v[MX];
int dist[MX];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    while(M--){
        int a,b,c;
        cin >> a>>b>>c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    cin >> S>>E;
    fill(dist,dist+N+1,INF);
    dist[S] = 0;
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
	pq.push({dist[S],S});
    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if(dist[curNode] != curCost)continue;

        for(int i=0;i<v[curNode].size();i++){
            int nxCost = v[curNode][i].first;
            int nxNode = v[curNode][i].second;

            if(dist[nxNode] <= dist[curNode]+nxCost)continue;
            dist[nxNode] = dist[curNode]+nxCost;
            pq.push({dist[nxNode],nxNode});
        }
    }

    cout << dist[E] << '\n';
    return 0;
}