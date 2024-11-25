#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;

// 벨만 포드 알고리즘 (음수 간선 처리 최단 거리 구하기)

const int MX = 502;
const int INF = 1e9;

vector<tuple<int,int,int>> edges;
long long d[MX]; // 거리 값, 오버플로우 언더 플로우 방지
int N,M;

bool bellman_ford(int s){
    d[s] = 0;

    // n-1 번의 라운드 반복
    for(int i=1;i<=N;i++){
        // 매 반복마다 모든 간선을 하나씩 확인
        for(int j=0;j<M;j++){
            int from, to, cost;
            // 튜플의 값을 분해
            tie(from,to,cost) = edges[j];
            
            // 한번이라도 계산된 정점에 대해서만 (단절된 정점은 제외)
            if( d[from] == INF)continue;

            // 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if( d[to] > d[from] + cost){
                d[to] = d[from] + cost; // 최단 거리 테이블 갱신

                // N번째에도 최단 거리가 갱신된다면 음수 사이클이 존재!
                if( i == N) return true;
            }
        }
    }

    return false;
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N >> M;

    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }

    fill_n(d,MX,INF);

    bool cycle = bellman_ford(1);

    if(cycle){
        cout << "-1\n";
        return 0;
    }

    for(int i=2;i<=N;i++){
        if(d[i] == INF) cout << "-1\n";
        else cout << d[i] << '\n';
    }

	return 0;
}