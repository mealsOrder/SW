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

    // 크루스칼 알고리즘 (최소 비용 계산 및 평균 반환)
    int kruskalWithGraphAverage() {
        // 간선을 가중치 기준으로 오름차순 정렬
        sort(edges.begin(), edges.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<2>(a) < get<2>(b); // 가중치 기준 정렬
        });

        vector<tuple<int, int, int>> mst; // 최소 스패닝 트리 (또는 숲)
        vector<int> componentAverages; // 각 컴포넌트의 평균
        unordered_set<int> connectedNodes;

        int mstCost = 0;

        for (const auto& [u, v, weight] : edges) {
            if (Find(u) != Find(v)) { // 같은 집합이 아니면 간선 추가
                Union(u, v);
                mst.emplace_back(u, v, weight);
                mstCost += weight;
                connectedNodes.insert(u);
                connectedNodes.insert(v);
            }
        }

        // 연결된 컴포넌트 계산
        unordered_set<int> independentNodes;
        for (int i = 0; i < numVertices; i++) {
            if (Find(i) == i) {
                independentNodes.insert(i);
            }
        }

        // 각 컴포넌트별 평균 비용 계산
        for (int root : independentNodes) {
            int nodeCount = 0;
            int componentCost = 0;

            for (const auto& [u, v, weight] : mst) {
                if (Find(u) == root || Find(v) == root) {
                    componentCost += weight;
                    connectedNodes.insert(u);
                    connectedNodes.insert(v);
                }
            }

            nodeCount = static_cast<int>(connectedNodes.size());
            if (nodeCount > 0) {
                componentAverages.push_back(componentCost / nodeCount); // 정수 계산
            }
        }

        // 평균값 계산
        int totalSum = 0;
        for (int avg : componentAverages) {
            totalSum += avg;
        }
        int finalAverage = (componentAverages.size() > 0) ? totalSum / static_cast<int>(componentAverages.size()) : 0;

        // 출력
        cout << "열결된 노드 수: " << connectedNodes.size() << '\n';
        cout << "연결된 그래프의 개수: " << componentAverages.size() << "\n";
        cout << "최종 평균값: " << finalAverage << "\n";
        
        return finalAverage;
    }
};

int main() {
    int numVertices = 7; // 정점 수
    Graph graph(numVertices);

    // 간선 추가
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 7);
    graph.addEdge(3, 4, 6);
    graph.addEdge(4, 5, 5);
    graph.addEdge(8, 9, 5);

    cout << "정점 수: " << graph.getNumVertices() << "\n";

    // 크루스칼 알고리즘 실행 및 결과 출력
    int finalAverage = graph.kruskalWithGraphAverage();

    return 0;
}
