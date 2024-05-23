#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1001;
int map[MAX][MAX]; // 좌표를 저장할 2차원 배열
bool visited[MAX][MAX]; // 방문 여부를 저장할 2차원 배열
int dx[] = {0, 1, 0, -1}; // 우, 하, 좌, 상 방향을 나타내는 배열
int dy[] = {-1, 0, 1, 0}; // 우, 하, 좌, 상 방향을 나타내는 배열
int R, C, K; // 입력값 저장을 위한 변수


/**
 * 행과 열이 헷갈리는 부분에 대해
 * 입력받은 C와 R은 각각 열과 행의 크기를 나타냅니다. 
 * 따라서 DFS 함수에서 y는 행 좌표, x는 열 좌표를 나타냅니다. 
 * 출력 시 x+1은 열 번호, R-y는 행 번호를 나타냅니다.
*/

void DFS(int y, int x, int cnt, int dir) {
    // 현재 좌표가 K번째 위치라면 출력 후 종료
    if (cnt == K) {
        cout << x+1 << " " << R - y << endl;
        return;
    }

    // 현재 좌표를 방문했다고 표시하고 번호 매김
    visited[y][x] = true;
    map[y][x] = cnt + 1;

    // 현재 방향으로 한 칸 이동한 좌표
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    // 이동한 좌표가 맵 범위를 벗어나거나 이미 방문했다면
    if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx]){
        // 방향을 바꾸어 다시 이동
        dir = (dir + 1) % 4;
        ny = y + dy[dir];
        nx = x + dx[dir];
    }

    // 다음 좌표로 이동하여 DFS 수행
    DFS(ny, nx, cnt + 1, dir);
}

int main() {
    cin >> C >> R >> K; // 입력받은 C, R, K를 저장

    // K가 맵의 크기를 넘는다면 0 출력
    if (K > C * R) {
        cout << "0" << endl;
        return 0;
    }

    // 시작 좌표를 (R-1, 0)으로 하여 DFS 수행
    DFS(R - 1, 0, 1, 0);

    return 0;
}