#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987987987;
const int MAX_N = 1001;

vector<int> v[MAX_N];
vector<int> cost[MAX_N];

int bfs(int start, int end) {
    int dist[MAX_N];
    fill(dist, dist + MAX_N, INF);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == end) {
            return dist[end];
        }
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            int new_dist = dist[cur] + cost[cur][i];
            if (new_dist < dist[next]) {
                dist[next] = new_dist;
                q.push(next);
            }
        }
    }
    return INF;
}

int main() {
    int N, M;
    cin >> N >> M;

    // 그래프 정보 입력
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(b);
        v[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
    }

    // 반드시 거쳐야 하는 두 정점 입력
    int A, B;
    cin >> A >> B;

    // BFS로 최단 경로 찾기
    long long int dist1 = bfs(1, A);
    long long int dist2 = bfs(A, B);
    long long int dist3 = bfs(B, N);

    // 최종 답 출력
    long long int ans = dist1 + dist2 + dist3;
    
	cout << ans << "\n";

    return 0;
}
