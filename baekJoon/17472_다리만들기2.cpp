#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int map[11][11], label[11][11];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int island = 0;

vector<tuple<int, int, int>> edges;
vector<int> parent;

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x < y) parent[y] = x;
    else parent[x] = y;
}

void bfs(int x, int y, int id) {
    queue<pair<int, int>> q;
    q.push({x, y});
    label[x][y] = id;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (map[nx][ny] == 1 && label[nx][ny] == 0) {
                    label[nx][ny] = id;
                    q.push({nx, ny});
                }
            }
        }
    }
}

void findBridges() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (label[i][j] == 0) continue;
            int from = label[i][j];

            for (int dir = 0; dir < 4; dir++) {
                int len = 0;
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                while (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                    if (label[nx][ny] == from) break; // 같은 섬
                    if (label[nx][ny] > 0) { // 다른 섬
                        if (len >= 2)
                            edges.push_back({len, from, label[nx][ny]});
                        break;
                    }
                    if (map[nx][ny] == 1) break;

                    len++;
                    nx += dx[dir];
                    ny += dy[dir];
                }
            }
        }
    }
}

int kruskal() {
    sort(edges.begin(), edges.end());
    parent.resize(island + 1);
    for (int i = 1; i <= island; i++) parent[i] = i;

    int total = 0, cnt = 0;
    for (auto edge : edges) {
        int cost,u,v;
        tie(cost,u,v) = edge;
        if (Find(u) != Find(v)) {
            Union(u, v);
            total += cost;
            cnt++;
        }
    }

    return (cnt == island - 1) ? total : -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (map[i][j] == 1 && label[i][j] == 0)
                bfs(i, j, ++island);

    findBridges();



    cout << kruskal() << '\n';
}
