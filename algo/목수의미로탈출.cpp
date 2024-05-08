#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int N, M; // ������ ���� ���̿� ���� ����
int map[MAX][MAX]; // ���� ����
int dist[MAX][MAX][2]; // �� ��ǥ������ �ִܰŸ� ���� (0: ���� �μ��� ���� ���, 1: ���� �μ��� �� ���)
int dx[4] = {-1, 1, 0, 0}; // �����¿� �̵� ����
int dy[4] = {0, 0, -1, 1};

int BFS() {
    // ť�� �ʱ� ��ǥ ����
    queue<pair<pair<int, int>, int>> q; // (x, y), ���� �μ��� �ʾ����� 0, �ν����� 1
    q.push({{N-1, 0}, 0}); // ����� (N-1, 0)���� ����, ���� �μ��� ���� ����
    dist[N-1][0][0] = 0; // ����� �Ÿ��� 0�� ����

    while (!q.empty()) { // ť�� �� ������ �ݺ�
        int x = q.front().first.first; // ���� x ��ǥ
        int y = q.front().first.second; // ���� y ��ǥ
        int wall = q.front().second; // ���� ���� �μ� ���� (0: �μ��� ����, 1: �μ�)
        q.pop(); // ť���� ���� ��ǥ ����

        if (x == 0 && y == M-1) { // �������� ������ ���
            return dist[x][y][wall]; // ������������ �Ÿ� ��ȯ
        }

        // �����¿�� �̵��� �� �ִ� ��ǥ Ȯ��
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; // ���� x ��ǥ
            int ny = y + dy[i]; // ���� y ��ǥ

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) { // ���� ���� ���� �ִ� ���
                if (map[nx][ny] == 0 && dist[nx][ny][wall] == 0) { // �� �� �ִ� ���̰�, ���� �湮���� ���� ���
                    q.push({{nx, ny}, wall}); // ť�� �߰�
                    dist[nx][ny][wall] = dist[x][y][wall] + 1; // �Ÿ� ���� ����
                } else if (map[nx][ny] == 1 && wall == 0 && dist[nx][ny][1] == 0) { // �������� �μ� �� �ִ� ���
                    q.push({{nx, ny}, 1}); // ť�� �߰�
                    dist[nx][ny][1] = dist[x][y][0] + 1; // ���� �μ� ����� �Ÿ� ���� ����
                }
            }
        }
    }

    return -1; // �������� �������� ���� ��� -1 ��ȯ
}

int main() {
    // ���� ũ�� �Է¹ޱ�
    cin >> N >> M;

    // ���� ���� �Է¹ޱ�
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            dist[i][j][0] = dist[i][j][1] = 0; // �ʱ� �Ÿ��� 0���� ����
        }
    }

    // BFS �����Ͽ� �ִܰŸ� ���ϱ�
    int result = BFS();
    
	// �������� �������� ���� ��� -1 ���
    cout << result << endl; // ������������ �ִܰŸ� ���
    

    return 0;
}