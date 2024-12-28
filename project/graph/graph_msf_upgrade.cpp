#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm> // std::sort
#include <unordered_map>
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

    // Union-Find 초기화
    void resetUnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i; // 각 노드를 자신의 부모로 초기화
        }
    }

public:
    // 생성자
    Graph(int vertices) : numVertices(vertices) {
        resetUnionFind(vertices);
    }

    // 소멸자
    ~Graph() {
        releaseResources();
        cout << "Graph 객체가 소멸되었습니다.\n";
    }

    // 리소스 정리 함수
    void releaseResources() {
        edges.clear();  // 간선 정보 정리
        parent.clear(); // 부모 배열 정리
        rank.clear();   // 랭크 배열 정리
        vector<tuple<int, int, int>>().swap(edges); // 메모리 해제
        vector<int>().swap(parent);
        vector<int>().swap(rank);
    }

    // 정점 개수 반환
    int getNumVertices() const {
        return numVertices;
    }

    // 간선 추가 함수
    void addEdge(int from, int to, int weight) {
        edges.emplace_back(from, to, weight);
    }

    // 연결 컴포넌트를 계산하고 컴포넌트별 MST를 계산
    void kruskalForConnectedComponents() {
        // 간선을 가중치 기준으로 오름차순 정렬
        sort(edges.begin(), edges.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<2>(a) < get<2>(b); // 가중치 기준 정렬
        });

        // Union-Find를 통해 연결된 컴포넌트를 구분
        for (const auto& [u, v, weight] : edges) {
            if (Find(u) != Find(v)) {
                Union(u, v);
            }
        }

        // 각 컴포넌트의 노드 집합 생성
        unordered_map<int, vector<int>> components;
        for (int i = 0; i < numVertices; i++) {
            components[Find(i)].push_back(i);
        }

        // 컴포넌트별로 MST 계산
        cout << "컴포넌트별 최소 스패닝 숲 구성:\n";
        for (const auto& [componentRoot, nodes] : components) {
            // Union-Find 초기화 (각 컴포넌트에 대해 독립적으로 처리)
            resetUnionFind(numVertices);

            vector<tuple<int, int, int>> mst; // 현재 컴포넌트의 MST
            int mstCost = 0;

            // 간선 처리 (현재 컴포넌트의 간선만 포함)
            for (const auto& [u, v, weight] : edges) {
                // 현재 컴포넌트의 간선만 처리
                if (Find(u) == Find(componentRoot) && Find(v) == Find(componentRoot)) {
                    if (Find(u) != Find(v)) { // 같은 집합이 아니면 간선 추가
                        Union(u, v);
                        mst.emplace_back(u, v, weight);
                        mstCost += weight; // MST 비용 추가
                    }
                }
            }

            // 결과 출력
            cout << "컴포넌트 루트: " << componentRoot << " (노드 수: " << nodes.size() << ")\n";
            for (const auto& [u, v, weight] : mst) {
                cout << u << " - " << v << " (가중치: " << weight << ")\n";
            }
            cout << "컴포넌트 MST 비용: " << mstCost << "\n\n";
        }
    }
};

int main() {
    int numVertices = 6; // 정점 수
    Graph graph(numVertices);

    // 간선 추가 (연결된 컴포넌트 내 간선만 추가)
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 2);
    graph.addEdge(3, 4, 1);
    graph.addEdge(4, 5, 5);

    cout << "정점 수 : " << graph.getNumVertices() << '\n';

    // 컴포넌트별 MST 계산
    graph.kruskalForConnectedComponents();

    return 0;
}
