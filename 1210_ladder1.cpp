#include<iostream>
#include<cstring>
using namespace std;

int ladder[101][101]; // 100x100 ũ���� ��ٸ� ������ ������ 2���� �迭

int dx[3] = {0, 0, -1}; // ��, ��, �� ���� �̵��� ���� x ��ǥ ��ȭ��
int dy[3] = {-1, 1, 0}; // ��, ��, �� ���� �̵��� ���� y ��ǥ ��ȭ��

// DFS(Depth-First Search) �˰����� ����Ͽ� ��ٸ� Ž��
int DFS(int a, int b) {
    int x = a; // ���� x ��ǥ
    int y = b; // ���� y ��ǥ
    
    while (1) { // ������(x == 0)�� ������ ������ �ݺ�
        if (x == 0) return y; // ������ ���� �� ���� y ��ǥ ��ȯ
        for (int i = 0; i < 3; i++) { // ��, ��, �� ���� Ž��
            int nx = x + dx[i]; // ���� x ��ǥ
            int ny = y + dy[i]; // ���� y ��ǥ

            // ���� ��ǥ�� ��ٸ� ������ ����ų� ��ΰ� ���� ��� continue
            if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100) continue;
            if (ladder[nx][ny] == 0) continue;
            
            // ���� ��ǥ�� �̵�
            x = nx;
            y = ny;
            ladder[nx][ny] = 0; // �湮 ǥ��
            break;
        }
    }
    return y;
}

int main(void) {
    int num;

    for (int T = 1; T <= 10; T++) { // 10���� �׽�Ʈ ���̽� ó��
        memset(ladder, 0, sizeof(int) * 101 * 101); // ��ٸ� ���� �ʱ�ȭ
        cin >> num; // �׽�Ʈ ���̽� ��ȣ �Է�

        // ��ٸ� ���� �Է�
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> ladder[i][j];
            }
        }

        // �� �Ʒ� �� Ž���Ͽ� ��� ���� ã��
        for (int i = 0; i < 100; i++) {
            if (ladder[99][i] == 2) { // ������ ã��
                int ans = DFS(99, i); // DFS �˰��� ����
                cout << '#' << num << ' ' << ans << '\n'; // ��� ���
                break;
            }
        }
    }
    return 0;
}