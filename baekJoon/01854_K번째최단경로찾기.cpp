#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 1001;
const int INF = 1e9;

// 인접 리스트 [출발] {비용,도착}
vector<pair<int,int>>v[MX];

/**
 * @brief priority_queue<int,vector<int>,less<int>> dist[MX];
 * 이 코드는 각 노드에서 K번째 최단 경로를 찾기 위해 사용
 * 각 노드에서 경로 비용들을 dist(우선순위 큐 - 최대 힙) 에 저장
 * 가장 큰 값이 우선순위 큐의 맨 위에 위치 하기에 큐의 크기가 K일때, 
 * 새로운 값의 크기를 비교하여 K번째 최단 경로보다 큰 값은 제거하고 더 작은 값만 남겨둘 수 있음
 */

// K번째 최단 거리들을 저장 할 우선 순위 큐, 최대 힙을 만들기 위해서 less 사용
// less<int> 는 기본적으로 큰 값을 우선순위 큐의 맨 위에 두기 때문에,
// dist는 큰 값을 먼저 꺼내는 최대 힙이 된다.
priority_queue<int,vector<int>,less<int>> dist[MX];

// 다익스트라 알고리즘을 위한 우선순위 큐
priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;

int N,M,K; // 노드수, 간선수, K번째 최단 경로
int s = 1; // 시작 노드 (문제에서 1로 고정)

// 다익스트라 알고리즘 함수
void dijkstra(){
    // 시작 노드 s에 대한 초기화
    pq.push({0,s});     // 시작 노드의 거리는 0으로 우선 순위 큐에 삽입
    dist[s].push(0);    // 시작 노드의 거리는 0으로 초기화

    // 우선순위 큐가 빌 때까지 반복
    while(!pq.empty()){
        int curCost = pq.top().first;       // 현재 노드까지의 비용
        int curNode = pq.top().second;      // 현재 노드
        pq.pop();

        // 현재 노드와 연결된 인접 노드들을 탐색
        for(int i=0;i<v[curNode].size();i++){
            int nxCost = v[curNode][i].first;       // 인접 노드까지의 추가 비용
            int nxNode = v[curNode][i].second;      // 다음 인접 노드

            // 인접 노드까지의 새로운 비용 계산
            int newCost = curCost + nxCost;

            // 인접 노드에 저장된 K번째 최단 거리보다 작은 개수의 최단 거리가 있을 경우
            if(dist[nxNode].size() < K){
                dist[nxNode].push(newCost);    // 새로운 비용을 삽입
                pq.push({newCost,nxNode});     // 우선순위 큐에 인접 노드와 새로운 비용 삽입
            }
            // 인접 노드에 K개의 최단 거리가 이미 저장되어 있지만, 새로운 비용이 더 작을 경우
            else if(dist[nxNode].top() > newCost){
                dist[nxNode].pop();         // 기존의 가장 큰 최단 거리 제거
                dist[nxNode].push(newCost); // 새로운 더 작은 비용을 추가
                pq.push({newCost,nxNode});  // 우선순위 큐에 인접 노드와 새로운 비용 삽입
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);

    cin >> N >> M >> K;

    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;

        v[a].push_back({c,b});

    }
    // 다익스트라 알고리즘 실행 -> 여기서 나는 for문 안에 넣어서 돌려 틀린 값을 저장
    dijkstra();

    // 각 노드에 대한 K번째 최단 거리 출력
    for(int i=1;i<=N;i++){
        if(dist[i].size() < K) cout << -1 << '\n';
        else{
            cout << dist[i].top() << '\n';
        }
    }

    return 0;
}