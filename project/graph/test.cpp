#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm> // std::sort
#include <unordered_set>
#include <unordered_map>
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

    // MST 생성 후 비용 계산
    int calculateMSTAverageCost() {
        // 간선을 가중치 기준으로 오름차순 정렬
        sort(edges.begin(), edges.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<2>(a) < get<2>(b); // 가중치 기준 정렬
        });

        vector<tuple<int, int, int>> mst; // 최소 스패닝 트리 (또는 숲)
        unordered_map<int, pair<int, int>> componentData; // {컴포넌트 루트, {총 비용, 노드 수}}

        // 간선 처리
        for (const auto& [u, v, weight] : edges) {
            if (Find(u) != Find(v)) { // 같은 집합이 아니면 간선 추가
                Union(u, v);
                mst.emplace_back(u, v, weight);

                // 컴포넌트 루트 찾기
                int rootU = Find(u);
                int rootV = Find(v);

                // 컴포넌트 데이터 업데이트
                if (componentData.find(rootU) == componentData.end()) {
                    componentData[rootU] = {0, 0}; // 초기화
                }
                if (componentData.find(rootV) == componentData.end()) {
                    componentData[rootV] = {0, 0}; // 초기화
                }

                componentData[rootU].first += weight; // 비용 누적
                componentData[rootU].second++;       // 노드 수 증가
            }
        }

        // 각 컴포넌트의 비용/노드 수를 누적합 계산
        int totalSum = 0;
        for (const auto& [root, data] : componentData) {
            int totalCost = data.first;
            int nodeCount = data.second + 1; // 간선 수 + 1 = 노드 수
            totalSum += totalCost / nodeCount;
        }

        // 최종 평균 계산
        int componentCount = componentData.size();
        int finalAverage = (componentCount > 0) ? totalSum / componentCount : 0;

        // 출력
        cout << "연결된 그래프의 개수: " << componentCount << "\n";
        cout << "최종 평균값: " << finalAverage << "\n";

        return finalAverage;
    }
};

int main() {
    int numVertices = 6; // 정점 수
    Graph graph(numVertices);

    // 간선 추가
    // graph.addEdge(0, 1, 4);
    // graph.addEdge(0, 2, 3);
    // graph.addEdge(1, 2, 2);
    // graph.addEdge(3, 4, 1);
    // graph.addEdge(4, 5, 5);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 1);
    graph.addEdge(4, 5, 5);
    cout << "정점 수: " << graph.getNumVertices() << "\n";

    // MST 평균 비용 계산
    cout << graph.calculateMSTAverageCost();

    return 0;
}
