#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MX = 100001;
const int INF = 987987987;
int N,M,K;
vector<pair<int,int>>v[MX];
int dist[MX];
int arr[MX];
int ans_d;
int ans_n;
int dijkstra(int st, int en){
    priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
    fill(dist,dist+N+1,INF);
    dist[st]=0;
    pq.push({dist[st],st});

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        if(curNode == en) return dist[en];
        pq.pop();
        if(dist[curNode] != curCost) continue;
        for(int i=0;i<v[curNode].size();i++){
            int nxCost = v[curNode][i].first;
            int nxNode = v[curNode][i].second;

            if(dist[nxNode] > dist[curNode]+nxCost){
                dist[nxNode] = dist[curNode]+nxCost;
                pq.push({dist[nxNode],nxNode});
            }
        }
    }
    return INF;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> M >> K;

    while(M--){
        int a,b,c;
        cin >> a >> b >> c;
        v[b].push_back({c,a});
    }
    for(int i=0;i<K;i++){
        cin >> arr[i];       
    }
    for(int j=0;j<K;j++){
        vector<pair<int,int>>a;
        for(int i=1;i<=N;i++){
            int ddd = dijkstra(arr[j],i);
            if( ddd != INF){
                a.push_back({ddd,i});
            }
        }
        sort(a.begin(),a.end(),greater<>());
        
        ans_d = max(ans_d,a[0].first);
        ans_n = max(ans_d,a[0].second);
    }
    cout << ans_n << '\n'; 
    cout << ans_d << '\n';
    return 0;
}