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

    // 연결 컴포넌트를 계산하고 컴포넌트별 MST를 생성
    vector<vector<pair<int, int>>> kruskalForConnectedComponents() {
        // 간선을 가중치 기준으로 오름차순 정렬
        sort(edges.begin(), edges.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<2>(a) < get<2>(b); // 가중치 기준 정렬
        });

        // MST를 저장할 새 그래프
        vector<vector<pair<int, int>>> mstGraph(numVertices);

        // Union-Find를 통해 연결된 컴포넌트를 구분
        for (const auto& [u, v, weight] : edges) {
            if (Find(u) != Find(v)) { // 같은 집합이 아니면 간선 추가
                Union(u, v);
                mstGraph[u].emplace_back(v, weight);
                mstGraph[v].emplace_back(u, weight);
            }
        }

        return mstGraph;
    }

    // BFS를 사용하여 그래프 탐색후 지표 계산
    double bfsGraph(const vector<vector<pair<int, int>>>& graph) {
        vector<bool> visited(numVertices, false);
        double ans = 0;
        for (int startNode = 0; startNode < numVertices; ++startNode) {
            if (visited[startNode]) continue;

            // BFS 초기화
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

            // 컴포넌트 결과 출력
            cout << "연결된 노드 개수: " << nodeCount << ", 총 최소 거리: " << totalWeight << "\n";
            
        }
        return ans;
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

    //graph.kruskal();

    // 최소 스패닝 숲 계산
    auto mstGraph = graph.kruskalForConnectedComponents();

    // BFS를 통해 연결된 그래프 탐색
    graph.bfsGraph(mstGraph);
    
    return 0;
}
