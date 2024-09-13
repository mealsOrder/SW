#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

const int INF = 987987987;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// BFS를 사용하여 최단 거리를 구하는 함수
int BFS(vector<vector<int>>& parkingLot, int tx, int ty) {
    int x = parkingLot.size();
    int y = parkingLot[0].size();
    vector<vector<int>> dist(x, vector<int>(y, INF));

    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        if (curX == tx && curY == ty) {
            return dist[curX][curY];
        }

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
            if (parkingLot[nx][ny] == 1 || dist[nx][ny] <= dist[curX][curY] + 1) continue;

            dist[nx][ny] = dist[curX][curY] + 1;
            q.push({nx, ny});
        }
    }

    return -1; // 도달할 수 없는 경우
}

int main() {
    int x, y;
    cout << "주차장의 크기 (x, y): ";
    cin >> x >> y;

    vector<vector<int>> parkingLot(x, vector<int>(y));

    cout << "주차장 상태를 입력하세요 (0: 빈 자리, 1: 차가 있는 자리):\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> parkingLot[i][j];
        }
    }

    int tx, ty;
    cout << "목표 좌표 (tx, ty): ";
    cin >> tx >> ty;

    int result = BFS(parkingLot, tx, ty);

    if (result != -1)
        cout << "최단 거리: " << result << endl;
    else
        cout << "목표 지점에 도달할 수 없습니다." << endl;

    return 0;
}
