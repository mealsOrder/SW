#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1001;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int R, C, K;

void DFS(int y, int x, int cnt, int dir) {
    if (cnt == K) {
        cout << x+1 << " " << R - y << endl;
        return;
    }

    visited[y][x] = true;
    map[y][x] = cnt + 1;

    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (ny >= 0 && ny < R && nx >= 0 && nx < C && !visited[ny][nx]) {
        DFS(ny, nx, cnt + 1, dir);
    } else {
        dir = (dir + 1) % 4;
        ny = y + dy[dir];
        nx = x + dx[dir];
        if (ny >= 0 && ny < R && nx >= 0 && nx < C && !visited[ny][nx]) {
            DFS(ny, nx, cnt + 1, dir);
        }
    }
}

int main() {
    cin >> C >> R >> K;

    if (K > C * R) {
        cout << "0" << endl;
        return 0;
    }

    DFS(R - 1, 0, 1, 0);

    return 0;
}