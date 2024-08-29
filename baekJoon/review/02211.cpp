#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 1004;
const int INF = INT_MAX;
vector<pair<int,int>>v[MX];
int N,M;
int from[MX];
int dist[MX];

void dijkstra(int s){
    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq; //{비용,다음노드}
    fill(dist,dist+N+1,INF);
    dist[s]=0;
    pq.push({dist[s],s});

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        for(int i=0;i<v[curNode].size();i++){
            int nxCost = v[curNode][i].first;
            int nxNode = v[curNode][i].second;

            if(dist[nxNode] > dist[curNode] + nxCost){
                dist[nxNode] = dist[curNode] + nxCost;
                from[nxNode] = curNode; // 어디서 왔는지 경로 저장
                pq.push({dist[nxNode],nxNode});
            }

        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >>M;

    while(M--){
        int a,b,c;
        cin >> a>>b>>c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }

    dijkstra(1);
    cout << N -1 << '\n';
    for(int i=2;i<=N;i++){
        cout << from[i] << " " << i << '\n';
    }

    return 0;
}