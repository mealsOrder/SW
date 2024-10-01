#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 201;
const int INF = INT_MAX;
vector<pair<int,int>>adj[MX];
int dist[MX];
int dijstra(int st,int en){
    fill(dist,dist+MX,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[st] = 0;
    pq.push({dist[st],st});

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        if( curNode == en) return dist[en];
        pq.pop();

        if(dist[curNode] != curCost) continue;
        
        for(int i=0;i<adj[curNode].size();i++){
            int nxCost = adj[curNode][i].first;
            int nxNode = adj[curNode][i].second;

            if(dist[nxNode] > dist[curNode] + nxCost){
                dist[nxNode] = dist[curNode] + nxCost;
                pq.push({dist[nxNode],nxNode});
            }
        }

    }
    return 0;
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int ans = 0;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    return 0;
}