#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int M, N;
int map[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;

queue<pair<int, int>> q;

void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0) {
                map[nx][ny] = map[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    BFS();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                cout << -1 << '\n';
                return 0;
            }
            ans = max(ans, map[i][j]);
        }
    }

    cout << ans - 1 << '\n';

    return 0;
}