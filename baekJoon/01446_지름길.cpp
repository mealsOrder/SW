#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
/*
 * N : 지름길 갯수
 * D : 고속도로 길이
 * v : 경로 정보를 저장할 vector [from] {to,cost}
 * cost : 시작점으로 부터 특정 노드까지의 최단 거리를 저장해줄 vector
 */
const int MX = 10001;
const int INF = INT_MAX;
int N,D;
vector<vector<pair<int,int>>> v(MX); // v[MX]: 벡터의 배열, v(MX): 벡터의 벡터
vector<int> cost(MX,INF);

void dijkstra(int start, vector<vector<pair<int,int>>> v){
    // 노드별 최단거리 priority Queue {dist,node} 형태로 저장
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,start});
    while(!pq.empty()){
        int curDist = pq.top().first; // 현재 노드까지의 최단 거리
        int curNode = pq.top().second;// 현재 노드
        pq.pop();

        // 현재 노드 까지의 최단 거리가 이미 저장된 거리보다 크다면 더이상 볼 필요 없음
        for(int i=0;i<v[curNode].size();i++){
            int nxDist = curDist + v[curNode][i].second; // 현재 노드까지의 거리 + 다음 노드로 가는 비용
            int nxNode = v[curNode][i].first; // 다음 노드

            // 다음 노드로 가는 최단 거리가 기존에 저장된 거리보다 작다면 업데이트
            if(nxDist < cost[nxNode]){
                cost[nxNode] = nxDist;
                pq.push({nxDist,nxNode});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N>>D;
    // 지름길 사용하지 않고 그냥 지나가는 경로 정보
    for(int i=0;i<D;i++){
        v[i].push_back({i+1,1});
    }   

    // 지름길 정보 입력
    for(int i=0;i<N;i++){
        int from,to,dist;
        cin >> from >> to >> dist;
        // 도착/시작 지점이 고속도로 길이(D)를 넘어가면 저장x >> 역주행 불가
        // from ~ to 의 길이보다 dist 가 길면 저장 x >> 지름길이 아님
        // 지름길의 거리가 실제 경로 거리보다 크면 입력 무시 (지름길 아님)
        if(to>D||from>D|| (to-from) < dist ) continue;
        v[from].push_back({to,dist});
    }
    dijkstra(0,v);
    cout << cost[D];
    return 0;
}