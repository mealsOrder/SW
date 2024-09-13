#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
typedef long long ll;
using namespace std;
const int MX = 100'001;
const ll INF = LONG_LONG_MAX;
int N,M,K;
vector<pair<ll,int>>adj[MX];
priority_queue< pair<ll,int> , vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
ll dist[MX];
void dijkstra(){
    while(!pq.empty()){
        ll curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if(dist[curNode] != curCost) continue;
        for(int i=0;i<adj[curNode].size();i++){
            ll nxCost = adj[curNode][i].first;
            int nxNode = adj[curNode][i].second;

            if(dist[nxNode] > dist[curNode]+nxCost){
                dist[nxNode] = dist[curNode]+nxCost;
                pq.push({dist[nxNode],nxNode});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> M >> K;

    fill(dist+1,dist+N+1,INF);
    int a,b;
    ll c;
    while(M--){
        cin >> a >> b >> c;
        adj[b].push_back({c,a}); // 거꾸로 면접장들과 각 도시로 이동
    }
    int num;
    while(K--){
        cin >> num;
        dist[num]=0;
        pq.push({dist[num],num});
    }
    dijkstra();
    // dist 배열에서 가장 큰 값이 있는 인덱스를 구하는 코드
    // *max_element(dist+1,dist+N+1) = dist 배열에서 가장 큰 값
    int ans = max_element(dist+1,dist+N+1) - dist;

    cout << ans << '\n';
    cout << dist[ans] << '\n';

    return 0;
}