#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 805;
const int INF = INT_MAX;

vector<int> v[MAX];
vector<int> cost[MAX];

int dist[MAX];
int N, E;
queue<int> q;

int BFS(int start, int end) {
    fill(dist, dist + MAX, INF);
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            int next_cost = dist[cur] + cost[cur][i];

            if (dist[next] > next_cost) {
                dist[next] = next_cost;
                q.push(next);
            }
        }
    }

    return dist[end];
}

int main() {
    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(b);
        v[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
    }

    int v1, v2;
    cin >> v1 >> v2;

    int ans1 = BFS(1, v1) + BFS(v1, v2) + BFS(v2, N);
    int ans2 = BFS(1, v2) + BFS(v2, v1) + BFS(v1, N);

    int ans = min(ans1, ans2);

    if (ans >= INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}