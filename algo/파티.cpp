#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 1001;
const int INF = INT_MAX;
int N,M,K;
vector<pair<int,int>>v[MX];
int dist[MX];

int func(int s,int e){
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    fill(dist,dist+N+1,INF);
    dist[s] = 0;
    pq.push({dist[s],s});

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        if(curNode == e) return dist[e];
        pq.pop();

        for(int i=0;i<v[curNode].size();i++){
            int nxCost = v[curNode][i].first;
            int nxNode = v[curNode][i].second;
            if(dist[nxNode] <= dist[curNode]+nxCost) continue;
            dist[nxNode] = dist[curNode]+nxCost;
            pq.push({dist[nxNode],nxNode});
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N>>M>>K;

    while(M--){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({c,b});
    }
    int sum = 0;
    for(int i=1;i<=N;i++){
        sum += func(i,K);
        sum += func(K,i);
    }
    cout << sum << '\n';
    return 0;
}