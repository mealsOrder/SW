#include<iostream>  
#include<vector>     
#include<algorithm> 
#include<cstring>   

using namespace std;

/*
이 코드는 이분 그래프문제를 해결하는 것입니다. 
그래프의 정점들을 두 개의 색깔로 칠할 수 있는지 여부를 판단하는 문제입니다.

DFS알고리즘을 사용하여 그래프를 탐색하면서 
각 정점에 RED 또는 BLUE 색깔을 지정합니다. 
인접한 정점들이 서로 다른 색깔을 가지도록 합니다. 
만약 인접한 정점들의 색깔이 같다면 이분 그래프가 아닌 것으로 판단합니다.

그래프 정보와 방문 정보 초기화
모든 정점에 대해 DFS 탐색 수행
인접 정점들의 색깔 검사를 통해 이분 그래프 여부 판단
이분 그래프 여부 출력
이 코드는 O(V+E)의 시간 복잡도를 가지고 있습니다.
*/

const int MAX = 20001; // 정점의 최대 개수 상수 정의
const int RED = 1;     // 정점의 RED 색깔 상수 정의
const int BLUE = 2;    // 정점의 BLUE 색깔 상수 정의

int V, E;              // 정점의 개수와 간선의 개수를 저장할 변수
vector<int> v[MAX];    // 그래프 정보를 저장할 인접 리스트 배열
int visited[MAX];      // 각 정점의 방문 상태와 색깔 정보를 저장할 배열

// DFS 알고리즘을 이용해 그래프를 탐색하고 정점의 색깔을 칠하는 함수
void DFS(int x, int color) {
    visited[x] = color;  // 현재 정점 x의 색깔을 지정

    // 현재 정점 x와 연결된 모든 인접 정점 nx에 대해
    for (int i = 0; i < v[x].size(); i++) {
        int nx = v[x][i];

        // 아직 방문하지 않은 정점이라면
        if (!visited[nx]) {
            // 현재 정점과 반대 색깔로 칠하며 DFS 탐색 진행
            DFS(nx, 3 - color);
        }
    }
}

int main() {
    int T;  // 테스트 케이스의 개수를 저장할 변수

    // 테스트 케이스의 개수 입력 받기
    cin >> T;

    for (int t = 1; t <= T; t++) {
        // 정점의 개수와 간선의 개수 입력 받기
        cin >> V >> E;

        // 그래프 정보와 방문 정보 초기화
        for (int i = 1; i <= V; i++) v[i].clear();
        memset(visited, 0, sizeof(visited));

        // 간선 정보 입력 받기
        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        // 모든 정점에 대해 DFS 탐색 수행
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                DFS(i, RED);  // 첫 번째 정점은 RED로 칠함
            }
        }

        // 이분 그래프 판단
        bool isBigraph = true;
        for (int i = 1; i <= V; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                int next = v[i][j];
                // 인접한 정점의 색깔이 같다면 이분 그래프가 아님
                if (visited[i] == visited[next]) {
                    isBigraph = false;
                    break;
                }
            }
            if (!isBigraph) break;
        }

        // 이분 그래프 여부 출력
        if (isBigraph) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}