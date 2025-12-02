#include <bits/stdc++.h>
using namespace std;

const int MX = 101;
int n, m;
int board[MX][MX];
bool vis[MX][MX];

// 8방향
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

bool bfs(int sx, int sy) {
    queue<pair<int,int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;

    int h = board[sx][sy];     // 현재 평탄면(plateau)의 높이
    bool isPeak = true;        // 산봉우리인지 여부

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (board[nx][ny] > h) {
                // 주변에 더 높은 곳이 하나라도 있다 → 산봉우리 아님
                isPeak = false;
            }

            // 같은 높이이면서 아직 방문 X → 같은 봉우리 덩어리
            if (!vis[nx][ny] && board[nx][ny] == h) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return isPeak;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 아직 안 봤고, 높이가 0보다 큰 칸에서만 시작
            if (!vis[i][j] && board[i][j] > 0) {
                if (bfs(i, j)) cnt++;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}
