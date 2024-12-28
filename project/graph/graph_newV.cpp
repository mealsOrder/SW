#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm> // std::sort
#include <unordered_set>
#include <unordered_map>
#include <cmath>
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
    // 밑이 10인 로그를 계산하는 함수
    double log10(double x) {
        return log(x) / log(10);
    }
    // 정점 개수 반환
    int getNumVertices() const {
        return numVertices;
    }

    // 간선 추가 함수
    void addEdge(int from, int to, int weight) {
        edges.emplace_back(from, to, weight);
    }

    // mst비용 구하는 함수
    int calculateMSTTotalCost(const vector<tuple<int, int, int>>& mst) {
        int totalCost = 0;
        for (const auto& edge : mst) {
            int d = get<2>(edge);
            cout << d << ", ";
            totalCost += get<2>(edge);
        }
        cout << '\n';
        return totalCost;
    }

    // MST 생성 후 비용 계산 및 노드 수 계산
    int calculateMSTAverageCost() {
        sort(edges.begin(), edges.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<2>(a) < get<2>(b); // 가중치 기준 정렬
        });

        vector<tuple<int, int, int>> mst; // 최소 스패닝 트리 (또는 숲)
        unordered_map<int, unordered_set<int>> componentNodes; // 각 컴포넌트별 노드 집합

        // 간선 처리
        for (const auto& [u, v, weight] : edges) {
            if (Find(u) != Find(v)) {
                Union(u, v);
                mst.emplace_back(u, v, weight);
                int root = Find(u);
                componentNodes[root].insert(u);
                componentNodes[root].insert(v);
            }
        }
        
        
        int totalSum = 0;
        int totalNodeCnt = 0;
        for (const auto& [root, nodes] : componentNodes) {
            int componentCost = 0;
            for (const auto& [u, v, weight] : mst) {
                if (nodes.find(u) != nodes.end() && nodes.find(v) != nodes.end()) {
                    componentCost += weight;
                }
            }
            int nodeCount = nodes.size();
            totalNodeCnt += nodeCount;
            //totalSum += componentCost / nodeCount;
            totalSum += componentCost;
        }

        int componentCount = componentNodes.size();
        //int finalAverage = (componentCount > 0) ? totalSum / componentCount : 0;
        int finalValue = (componentCount > 0) ? totalSum : 0;

        // 출력
        for (const auto& [root, nodes] : componentNodes) {
            cout << "컴포넌트 루트 " << root << "의 노드 수: " << nodes.size() << "\n";
        }
        cout << "연결된 그래프의 개수: " << componentCount << "\n";
        cout << "연결된 노드 수: " << totalNodeCnt << "\n";
        //cout << "최종 평균값: " << finalAverage << "\n";
        cout << "코스트 합: " << finalValue << "\n";
        int mstValue = calculateMSTTotalCost(mst);
        cout << "mst 값: "<<mstValue << "\n";
        //double C = (double)(log((double)1/finalAverage * 100000));
        //double C = (double)((double)100000/finalValue);
        double C = (double)((double)100000/mstValue);
        cout << "계산값 C: " << C << '\n';

        double G = (double)( 0.5 * log10(componentCount+1) * exp(totalNodeCnt) );
        cout << "가중치 G: " << G << '\n';
        
        double res =  (double)sqrt((double)log10(C) * (double)totalNodeCnt * G);
        cout << "위험도 R: " << res << "\n";
        return res;
    }

};

int main() {
    // int numVertices = 8;
    // Graph graph(numVertices);
    // graph.addEdge(0, 1, 400);
    // graph.addEdge(0, 2, 300);
    // graph.addEdge(1, 2, 200);
    // graph.addEdge(1, 3, 100);
    // graph.addEdge(4, 5, 500);
    // graph.addEdge(6, 7, 900);

    int numVertices = 3;
    Graph graph(numVertices);
    graph.addEdge(0, 1, 681);
    graph.addEdge(0, 2, 690);
    graph.addEdge(1, 2, 200);
    cout << "정점 수: " << graph.getNumVertices() << "\n";
    int finalAverage = graph.calculateMSTAverageCost();
    return 0;
}
