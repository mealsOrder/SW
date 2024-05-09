#include <iostream>
#include <vector>
#include <climits> // 자료형의 최대값과 최소값을 제공하는 헤더

using namespace std;

const int MAX = 10000;
const int INF = INT_MAX; // INT_MAX 이것을 사용하기 위해 climits 헤더 사용
vector<int> graph[MAX]; // 그래프 정보 저장
int dist[MAX]; // 출발점부터의 최단 거리
bool visited[MAX]; // 방문 여부
int N, M;

// 다익스트라 알고리즘을 사용하여 start 정점에서부터의 최단 거리를 계산하는 함수
void dijkstra(int start) {
    // dist 배열을 최대값(무한대)으로 초기화
    fill(dist, dist + MAX, INF);
    dist[start] = 0; // 시작 정점의 거리를 0으로 설정

    // 정점들을 방문하지 않은 상태로 초기화
    fill(visited, visited + MAX, false);

    for (int i = 0; i < MAX; i++) {
        int min_dist = INF;
        int cur_node = -1;

        // 아직 방문하지 않은 정점 중에서 최단 거리를 가진 정점을 찾음
        for (int j = 0; j < MAX; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                cur_node = j;
            }
        }

        // 모든 정점을 방문했거나 최단 거리를 가진 정점이 없는 경우 종료
        if (cur_node == -1) break;

        visited[cur_node] = true; // 현재 정점을 방문 표시

        // 현재 정점에서 연결된 각 정점으로의 최단 거리를 갱신
        for (auto next : graph[cur_node]) {
            int next_node = next;
            int next_dist = 1 + dist[cur_node]; // 간선의 가중치가 모두 1로 가정

            // 다음 정점으로의 거리가 현재 저장된 거리보다 작은 경우 갱신
            if (next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
            }
        }
    }
}

int main() {
 
    cin >> N >> M; // 정점의 수 N과 간선의 수 M을 입력 받음

    // 간선 정보를 입력 받아 그래프를 생성
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // 양방향 그래프이므로 양쪽으로 연결

        // 

    }

    int start, end;
    cin >> start >> end; // 출발점과 도착점을 입력 받음

    dijkstra(start); // 다익스트라 알고리즘을 사용하여 최단 거리 계산

    cout << dist[end] << endl; // 도착점까지의 최단 거리 출력

    return 0;
}