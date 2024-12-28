#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm> // std::sort
#include <unordered_map>
#include <unordered_set>
#include <queue>
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

    // 크루스칼 알고리즘 (MST 생성)
    vector<vector<pair<int, int>>> kruskalForConnectedComponents() {
        sort(edges.begin(), edges.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<2>(a) < get<2>(b); // 가중치 기준 정렬
        });

        vector<vector<pair<int, int>>> mstGraph(numVertices);

        for (const auto& [u, v, weight] : edges) {
            if (Find(u) != Find(v)) {
                Union(u, v);
                mstGraph[u].emplace_back(v, weight);
                mstGraph[v].emplace_back(u, weight);
            }
        }

        return mstGraph;
    }

    // BFS로 MST 탐색
    void bfsGraph(const vector<vector<pair<int, int>>>& graph) {
        vector<bool> visited(numVertices, false);
        int connectedComponents = 0;

        for (int startNode = 0; startNode < numVertices; ++startNode) {
            if (visited[startNode]) continue;

            connectedComponents++;
            queue<int> q;
            q.push(startNode);
            visited[startNode] = true;

            int nodeCount = 0;
            int totalWeight = 0;

            while (!q.empty()) {
                int current = q.front();
                q.pop();
                nodeCount++;

                for (const auto& [neighbor, weight] : graph[current]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                        totalWeight += weight;
                    }
                }
            }

            cout << "연결된 노드 개수: " << nodeCount << ", 총 최소 거리: " << totalWeight << "\n";
        }

        cout << "연결된 그래프의 개수: " << connectedComponents << "\n";
    }
};

int main() {
    int numVertices = 4;
    Graph graph(numVertices);

    graph.addEdge(4, 2, 387);
    graph.addEdge(4, 3, 216);
    graph.addEdge(2, 3, 611);
    graph.addEdge(1, 0, 270);

    cout << "정점 수: " << graph.getNumVertices() << '\n';

    // MST 생성
    auto mstGraph = graph.kruskalForConnectedComponents();

    // BFS로 MST 탐색 및 정보 출력
    graph.bfsGraph(mstGraph);

    return 0;
}
