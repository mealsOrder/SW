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
        // 메모리 해제
        edges.clear();
        edges.shrink_to_fit();
        parent.clear();
        parent.shrink_to_fit();
        rank.clear();
        rank.shrink_to_fit();
    }

    // 정점 개수 반환
    int getNumVertices() const {
        return numVertices;
    }

    // 간선 추가 함수
    void addEdge(int from, int to, int weight) {
        edges.emplace_back(from, to, weight);
    }

    // 크루스칼 알고리즘 (최소 스패닝 숲 생성)
    std::pair<int, int> kruskal() {
        // 간선을 가중치 기준으로 오름차순 정렬
        sort(edges.begin(), edges.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<2>(a) < get<2>(b); // 가중치 기준 정렬
        });

        vector<tuple<int, int, int>> mst; // 최소 스패닝 트리 (또는 숲)
        unordered_set<int> connected_nodes;
        int mstCost = 0;

        // 간선 처리
        for (const auto& [u, v, weight] : edges) {
            if (Find(u) != Find(v)) { // 같은 집합이 아니면 간선 추가
                Union(u, v);
                mst.emplace_back(u, v, weight);
                connected_nodes.insert(u); // u를 연결된 노드 집합에 추가
                connected_nodes.insert(v); // v를 연결된 노드 집합에 추가
                mstCost += weight;
            }
        }

        // 연결되지 않은 노드 식별
        unordered_set<int> independentNodes;
        for (int i = 0; i < numVertices; i++) {
            if (Find(i) == i) { // 자신의 부모가 자신인 노드
                independentNodes.insert(i);
            }
        }

        return {static_cast<int>(connected_nodes.size()), mstCost};
    }
};