#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm> // std::fill 사용
#include <tuple>
using namespace std;

// 무한대 값 정의
const int INF = numeric_limits<int>::max();
vector<int> parent; // 부모 노드를 저장하는 배열 (Union-Find 구조)
vector<tuple<int,int,int>>t;
int ans;

// 오름차순 정렬을 위한 비교 함수
bool cmpAsc(tuple<int,int,int> &a, tuple<int,int,int>&b){
    return get<0>(a) < get<0>(b); 
}

// 내림차순 정렬을 위한 비교 함수
bool  cmpDes(tuple<int,int,int> &a, tuple<int,int,int>&b){
    return get<0>(a) > get<0>(b);
}
// 그래프 클래스 정의
class Graph {
private:
    int numVertices; // 정점의 개수
    vector<vector<pair<int, int>>> adjList; // 인접 리스트 (노드, 거리)
    vector<tuple<int,int,int>> kList; // 인접 리스트(튜플) {거리,출발id,도착id}
public:
    // 생성자
    Graph(int vertices) : numVertices(vertices), adjList(vertices + 1) {}

    // 간선 추가 함수
    void addEdge(int from, int to, int weight) {
        adjList[from].push_back(make_pair(to, weight));
        adjList[to].push_back(make_pair(from, weight)); // 양방향 그래프
    }

    // 다익스트라 알고리즘 함수
    int dijkstra(int start, int end) {
        vector<int> dist(numVertices + 1, INF); // 최단 거리 테이블
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({0, start}); // (거리, 노드)

        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            // 이미 처리된 노드인 경우 건너뜀
            if (currentDist > dist[currentNode]) continue;

            // 인접 노드 탐색
            for (auto &neighbor : adjList[currentNode]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;

                // 같은 노드로 돌아가는 경우 제외
                if (currentNode == nextNode) continue;

                // 더 짧은 경로가 발견된 경우
                if (dist[currentNode] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[currentNode] + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        // 끝 노드까지의 거리 반환
        return (dist[end] == INF ? -1 : dist[end]); // 도달 불가 시 -1 반환
    }


    
    // Find 연산 (Union-Find 알고리즘)
    // 경로 압축(Path Compression)을 사용하여 루트 노드를 찾음
    int Find(int x) {
        if (parent[x] == x) return x; // 자신이 루트 노드인 경우
        return parent[x] = Find(parent[x]); // 재귀적으로 루트 노드를 찾아 경로를 압축
    }

    // Union 연산 (Union-Find 알고리즘)
    // 두 집합을 합침
    void Union(int u, int v) {
        u = Find(u); // u의 루트 노드 찾기
        v = Find(v); // v의 루트 노드 찾기

        if (u > v) parent[u] = v; // 작은 루트 노드를 부모로 설정 (정렬된 트리를 유지)
        else parent[v] = u;       // 작은 루트 노드를 부모로 설정
    }

    // 두 노드가 같은 집합에 속해 있는지 확인
    bool isSameParent(int u, int v) {
        u = Find(u); // u의 루트 노드 찾기
        v = Find(v); // v의 루트 노드 찾기

        return u == v; // 같은 루트 노드를 가지면 같은 집합
    }

    // Kruskal 알고리즘 구현
    void kruskal() {
        // 간선 정보를 저장한 벡터 t를 가중치 기준으로 정렬
        sort(t.begin(), t.end(), cmpAsc);

        // 모든 간선을 하나씩 확인
        for (int i = 0; i < t.size(); i++) {
            int cost = get<0>(t[i]); // 현재 간선의 가중치
            int u = get<1>(t[i]);    // 간선의 시작 정점
            int v = get<2>(t[i]);    // 간선의 끝 정점

            // 두 정점이 같은 집합에 속하지 않는 경우만 추가
            if (!isSameParent(u, v)) {
                Union(u, v);     // 두 집합을 합침
                ans += cost;     // 간선의 가중치를 MST 비용에 추가
            }
        }

        // MST의 총 비용 출력
        cout << ans << '\n';
    }
};

int main() {
    // 정점 개수를 정의 ( 차량 갯수 )
    int vertices = 6;

    // 그래프 생성
    Graph graph(vertices);

    // 간선 추가 (출발id, 도착id, 거리)
    graph.addEdge(1, 2, 2); // 1 -> 2 거리 2
    graph.addEdge(1, 3, 4); // 1 -> 3 거리 4
    graph.addEdge(2, 3, 1); // 2 -> 3 거리 1
    graph.addEdge(2, 4, 7); // 2 -> 4 거리 7
    graph.addEdge(3, 5, 3); // 3 -> 5 거리 3
    graph.addEdge(4, 6, 1); // 4 -> 6 거리 1
    graph.addEdge(5, 6, 5); // 5 -> 6 거리 5

    
    vector<tuple<int,int,int>>atv;

    // 다익스트라 실행
    for(int i=1;i<=vertices;i++){
        atv.clear();
        for(int j=1;j<=vertices;j++){
            if(i == j)continue;
            cout << "출발 노드 " << i << "에서 도착 노드 " << j << "까지의 최단 거리: ";
            int result = graph.dijkstra(i, j);
            if (result != -1) { // 도달 가능한 경우만 저장
                atv.push_back({result, i, j});
            }
            if (result == -1)
                cout << "도달 불가능\n";
            else
                cout << result << "\n";
        }
        sort(atv.begin(),atv.end());
        // 가장 짧은 거리와 해당 출발/도착 노드 출력
        if (!atv.empty()) {
            int minDist = get<0>(atv[0]);
            int startNode = get<1>(atv[0]);
            int endNode = get<2>(atv[0]);
            cout << "가장 짧은 거리: " << minDist << '\n';
            cout <<  "출발 노드 " << startNode << "에서 도착 노드 " << endNode << '\n';
                 
        } else {
            cout << "출발 노드 " << i << "에서 도달 가능한 다른 노드가 없습니다.\n";
        }
    }

    cout << '\n';

    return 0;
}