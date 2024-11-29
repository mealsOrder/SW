#include<iostream>
#include<algorithm>
#include<cstring>
#include<tuple>
#include<vector>
using namespace std;
const int INF = 1e9;
const int MX = 501;
int N,M;
long long dist[MX];          // 각 노드 까지의 최단 거리 저장
vector<tuple<int,int,int>>v; // 간선 정보 저장 {from,to,cost}

// 벨만-포드 알고리즘 : 시작 노드 x로부터 최단 거리를 구하고 음수 사이클 판별
bool bellman_ford(int x){
    // 사직 노드의 거리는 0으로 설정
    dist[x] = 0;

    // 노드 수 만큼 반복
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            int from,to,cost;
            tie(from,to,cost) = v[j];

            // 시작 노드부터 도달할 수 없는 경우 무시
            if(dist[from] == INF) continue;

            // 더 짧은 거리가 존재하면 업데이트
            if(dist[to] > dist[from] + cost){
                dist[to] = dist[from] + cost;

                // N번째 반복에서도 업데이트가 발생하면 음수 사이클이 존재 하는거
                if( i == N) return true;
            }
        }
    }
    // 음수 사이클이 없는 경우
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back({a,b,c});
    }
    fill(dist,dist+N+1,INF);

    bool cycle = bellman_ford(1);

    // 음수 사이클 존재 여부 확인
    if(cycle){
        cout << "-1\n";
        return 0;
    }

    // 각 노드까지의 최단 거리 출력
    for(int i=2;i<=N;i++){
        // 도달 할 수 없는 경우 -1 출력
        if(dist[i] == INF) cout << "-1\n";
        else cout << dist[i] << '\n';   // 최단 거리 출력
    }

    return 0;
}