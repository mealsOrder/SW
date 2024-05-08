#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1001;

int N, M; // ������ ���� ���̿� ���� ����
int map[MAX][MAX]; // ���� ����
int dist[MAX][MAX]; // �� ��ǥ������ �ִܰŸ� ����
int dx[4] = {-1, 1, 0, 0}; // �����¿� �̵� ����
int dy[4] = {0, 0, -1, 1};

int BFS() {
    // ť�� ����� ��ǥ �ʱ�ȭ
    queue<pair<int, int>> q;
    q.push({N-1, 0});
    dist[N-1][0] = 0; // ����� �Ÿ��� 0���� ����

    while (!q.empty()) { // ť�� �� ������ �ݺ�
        int x = q.front().first; // ���� x ��ǥ
        int y = q.front().second; // ���� y ��ǥ
        q.pop(); // ť���� ���� ��ǥ ����

        if (x == 0 && y == M-1) { // �������� ������ ���
            return dist[0][M-1]; // ������������ �Ÿ� ��ȯ
        }

        // �����¿�� �̵��� �� �ִ� ��ǥ Ȯ��
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; // ���� x ��ǥ
            int ny = y + dy[i]; // ���� y ��ǥ

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && // ���� ���� ���� �ְ�
                map[nx][ny] == 0 && // �̵��� �� �ִ� �κ��̰�
                dist[nx][ny] == -1) { // ���� �湮���� ���� ���
                q.push({nx, ny}); // ť�� �߰�
                dist[nx][ny] = dist[x][y]+1; // �Ÿ� ���� ����
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
            dist[i][j] = -1; // �ʱ� �Ÿ��� -1�� ����
        }
    }

    // BFS �����Ͽ� �ִܰŸ� ���ϱ�
    int result = BFS();
    cout << result << endl; // ��� ���

    return 0;
}