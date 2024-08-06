#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

const int MX = 101;
const int INF = INT_MAX;
int N,M,R;
int item[MX];
int dist[MX];
vector<pair<int,int>>v[MX]; //[출발]{거리,도착}

void djikstra(int x){
    fill(dist,dist+N+1,INF);
    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;    
    dist[x] = 0;
    pq.push({dist[x],x});

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        //if(dist[curNode] != curCost)continue;
        for(int i=0;i<v[curNode].size();i++){
            int nxCost = v[curNode][i].first;
            int nxNode = v[curNode][i].second;

            if(dist[nxNode] > dist[curNode]+nxCost){
                dist[nxNode] = dist[curNode]+nxCost;
                pq.push({dist[nxNode],nxNode});
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> N>>M>>R;

    // 아이템 정보
    for(int i=1;i<=N;i++){
        int a;
        cin >> a;
        item[i] = a;
    }

    // 경로 정보
    while(R--){
        int a,b,c;
        cin >> a>>b>>c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    int ans = -1;
    for(int i=1;i<=N;i++){
        int itCnt = 0;
        djikstra(i);
        for(int j=0;j<=N;j++){
            if(dist[j] <=M){
                itCnt += item[j];
            }
        }
        ans = max(ans,itCnt);
    }
    cout << ans << '\n';
	return 0;
}