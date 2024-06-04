#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
using namespace std;
/**
 * V : 정점의 갯수
 * E : 간선갯수
 *                              인접 행렬    인접리스트
 *                    공간복잡도   O(v^2)       O(V+E)
 *             정점 u,v연결 확인   O(1)         O(min(deg(u),deg(v)))
 * 정점 v와 연결된 모든 정점 확인   O(V)         O(deg(v))
 *                 효율적인 상황     (1)          (2)
 * (1) 두 점의 연결여부를 자주 확인할때, E가 V^2에 가까울때
 * (2) 특정 정점에 연결된 모든 정점을 자주 확인할 때, E가 v^2보다 훨씬 작을때
*/
int main() {

    // 인접 행렬 (방향)
    int adj_matrix1[10][10]={};
    int v1,e1;
    cin >> v1>>e1;
    for(int i=0;i<e1;i++){
        int u,v;
        cin >> u>>v;
        adj_matrix1[u][v]=1;
    }

    // 인접 행렬 (무방향)
    int adj_matrix2[10][10]={};
    int v2,e2;
    for(int i=0;i<e2;i++){
        int u,v;
        cin >> u>>v;
        adj_matrix2[u][v]=1;
        adj_matrix2[v][u]=1;
    }

    // 인접 리스트
    // 정점이 많고 간선은 상대적으로 작은 상황에서 사용
    // 방향 그래프 인접 리스트
    vector<int>adj1[10];
    int v,e;
    cin >>v>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin >> u>>v;
        adj1[u].push_back(v);
    }

    // 무방향 그래프 인접 리스트
    vector<int>adj2[10];
    cin >> v>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin >>u>>v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    // 만약 STL 을 사용하지 못하게 하면?



    return 0;
}