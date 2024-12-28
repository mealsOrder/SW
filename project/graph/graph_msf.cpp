#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm> // std::sort
#include <unordered_set>
using namespace std;

class Graph {
private:
    int numVertices; // 정점의 개수
    vector<tuple<int, int, int>> edges; // 간선 정보 {출발 노드, 도착 노드, 가중치}
    vector<int> parent; // Union-Find 부모 배열
    vector<int> rank;   // Union-Find 랭크 배열

    // Union-Find: Find 연산 (경로 압축)
    int Find(int x) {
        if (parent[x] != x) {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }

    // Union-Find: Union 연산 (랭크 기반)
    void Union(int u, int v) {
        int rootU = Find(u);
        int rootV = Find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

public:
    // 생성자
    Graph(int vertices) : numVertices(vertices), parent(vertices), rank(vertices, 0) {
        for (int i = 0; i < vertices; i++) {
            parent[i] = i; // 각 노드를 자신의 부모로 초기화
        }
    }
    // 소멸자
    ~Graph() {
        // 객체 소멸 시 호출될 작업 수행
        cout << "Graph 객체가 소멸되었습니다. 사용한 리소스를 정리합니다." << endl;
        edges.clear();  // 간선 정보 정리
        parent.clear(); // 부모 배열 정리
        rank.clear();   // 랭크 배열 정리
    }

    // getter
    int getNumVertices(){
        return numVertices;
    }

    // 간선 추가 함수
    void addEdge(int from, int to, int weight) {
        edges.emplace_back(from, to, weight);
        //edges.emplace_back(to, from, weight);
    }

    // 크루스칼 알고리즘 (최소 스패닝 숲 생성)
    void kruskal() {
        // 간선을 가중치 기준으로 오름차순 정렬
        sort(edges.begin(), edges.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<2>(a) < get<2>(b); // 가중치 기준 정렬
        });

        vector<tuple<int, int, int>> mst; // 최소 스패닝 트리 (또는 숲)
        int mstCost = 0;

        // 간선 처리
        for (const auto& [u, v, weight] : edges) {
            if (Find(u) != Find(v)) { // 같은 집합이 아니면 간선 추가
                Union(u, v);
                mst.emplace_back(u, v, weight);
                mstCost += weight;
            }
        }

        // 연결되지 않은 노드 출력
        unordered_set<int> independentNodes;
        for (int i = 0; i < numVertices; i++) {
            if (Find(i) == i) { // 자신의 부모가 자신인 노드 = 독립된 컴포넌트
                independentNodes.insert(i);
            }
        }
        cout << "연결되지 않은 노드:";
        for (int node : independentNodes) {
            if (independentNodes.size() > 1 || edges.empty()) {
                cout << node << " ";
            }
        }
        cout << endl;

        // MST 출력
        cout << "Minimum Spanning Forest 구성:\n";
        for (const auto& [u, v, weight] : mst) {
            cout << u << " - " << v << " (가중치: " << weight << ")\n";
        }
        cout << "Minimum Spanning Forest 총 비용: " << mstCost << "\n";
    }
};

int main() {
    int numVertices = 4; // 정점 번호: 0, 1, 3, 2 (노드 2는 연결되지 않음)
    Graph graph(numVertices);

    // 간선 추가
    graph.addEdge(4, 2, 387);
    graph.addEdge(4, 3, 216);
    graph.addEdge(2, 3, 611);
    graph.addEdge(1, 0, 270);

    cout << "정점 수 : " << graph.getNumVertices() << '\n';
    
    // 크루스칼 알고리즘 실행
    graph.kruskal();
    return 0;
}
