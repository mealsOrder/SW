#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 10001;
const int INF = INT_MAX;
int N,D;
vector<vector<pair<int,int>>>v(MX); // v[from]{to,cost}
vector<int>cost(MX,INF);

void dijkstra(int start,vector<vector<pair<int,int>>> v){
    // {dist,node} 거리순으로 정렬해야해서 dist부터
    priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>> >pq; 
    pq.push({0,start});
    
    while(!pq.empty()){
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        for(int i=0;i<v[curNode].size();i++){
            int nxNode = v[curNode][i].first;
            int nxDist = curDist + v[curNode][i].second;

            if(nxDist<cost[nxNode]){
                cost[nxNode] = nxDist;
                pq.push({nxDist,nxNode});
            }
        }
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >>D;

    // 일반 길 입력
    for(int i=0;i<D;i++){
        v[i].push_back({i+1,1});
    }

    // 고속도로 입력
    for(int i=0;i<N;i++){
        int from,to,dist;
        cin >> from >> to >> dist;
        if(D<to||D<from||(to-from)<dist)continue;
        v[from].push_back({to,dist});
    }
    dijkstra(0,v);
    cout << cost[D] << '\n';
    return 0;
}