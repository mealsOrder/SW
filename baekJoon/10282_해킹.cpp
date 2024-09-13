#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MX = 10001;
const int INF = 987987987;
int dist[MX];
vector<pair<int,int>>v[MX];
int N,D,C;
int cnt;
int ans;
void dijkstra(int s){
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
    fill(dist,dist+MX,INF);
    cnt = 0;
    dist[s]=0;
    ans = 0;
    pq.push({dist[s],s});

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if( dist[curNode] != curCost) continue;
        for(int i=0;i<v[curNode].size();i++){
            int nxCost = v[curNode][i].first;
            int nxNode = v[curNode][i].second;
            if(dist[nxNode] > dist[curNode] + nxCost){
                dist[nxNode] = dist[curNode] + nxCost;
                pq.push({dist[nxNode],nxNode});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin >> T;

    while(T--){
        cin >> N >> D >> C;

        for(int i=1;i<=N;i++)v[i].clear(); // 테스트 케이스 문제 초기화@!!!
        while(D--){
            int a,b,cc;
            cin >> a >> b >> cc;
            v[b].push_back({cc,a});
        }
        dijkstra(C);
        for(int i=1;i<=N;i++){
            if(dist[i] != INF){
                cnt++;
                ans = max(ans,dist[i]);
            }
        }
        cout << cnt << ' ' << ans << '\n';
    }
    return 0;
}