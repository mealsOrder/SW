#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 22;
const int FIXED_COL = 21; // 열 고정 크기
int dx[] = {1, 0, 0}; // 아래, 왼쪽, 오른쪽
int dy[] = {0, -1, 1};

int N, M;
string origin[MAX]; // 입력 미로
string map[MAX];    // 회전된 미로
int dist[MAX][FIXED_COL];
vector<int> v;       // 결과 저장

// row를 오른쪽으로 shift칸 밀고 앞은 X로 채우기
string buildShiftedRow(const string& row, int shift) {
    string shifted = string(shift, 'X') + row;
    shifted.resize(FIXED_COL, 'X');
    return shifted;
}

// BFS로 S → F 최단거리 탐색
int BFS(int sx, int sy, int ex, int ey) {
    for (int i = 0; i < N; i++) fill(dist[i], dist[i] + FIXED_COL, -1);

    queue<pair<int, int>> q;
    dist[sx][sy] = 1;
    q.push({sx, sy});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        if (x == ex && y == ey) return dist[x][y];
        q.pop();


        for (int i = 0; i < 3; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < FIXED_COL &&
                dist[nx][ny] == -1 && map[nx][ny] == 'O') {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1; // 도달 불가
}

// 백트래킹: 각 행의 회전 조합 생성
void backtrack(int row) {
    if (row == N) {
        int sx = -1, sy = -1, ex = -1, ey = -1;

        // S, F 위치 찾기
        for (int j = 0; j < FIXED_COL; j++) {
            if (map[0][j] == 'S') sx = 0, sy = j;
            if (map[N - 1][j] == 'F') ex = N - 1, ey = j;
        }

        if (sx == -1 || ex == -1) return;

        map[0][sy] = 'O';
        map[N - 1][ey] = 'O';

        int res = BFS(sx, sy, ex, ey);
        if (res != -1) v.push_back(res);

        // 원상복구
        map[0][sy] = 'S';
        map[N - 1][ey] = 'F';

        return;
    }

    for (int shift = 0; shift <= FIXED_COL - M; shift++) {
        map[row] = buildShiftedRow(origin[row], shift);
        backtrack(row + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) cin >> origin[i];

        v.clear();
        backtrack(0);

        if (v.empty()) cout << -1 << '\n';
        else cout << *min_element(v.begin(), v.end()) << '\n';
    }

    return 0;
}
