#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
#include<set>

using namespace std;


/*
�� �ڵ�� 4x4 ũ���� �����ǿ��� 7�ڸ� ���ڸ� ����� ������ �ذ��մϴ�.

s set �ڷᱸ���� �̿��Ͽ� ������� 7�ڸ� ���ڸ� �ߺ� ���� �����մϴ�.
DFS �Լ��� �̿��Ͽ� ��� ��ġ���� 7�ڸ� ���ڸ� ����� ������ �����մϴ�.
7�ڸ� ���ڸ� ������ٸ� s set�� �߰��մϴ�.
�����¿� �������� Ž���ϸ� ���� ��ġ�� ���ڸ� �߰��Ͽ� 
���� ��ġ�� DFS Ž���� �����մϴ�.
������ ������ ����� ��� continue�մϴ�.
��� �׽�Ʈ ���̽��� ���� �� ������ �����ϰ�, 
���������� ������� 7�ڸ� ������ ������ ����մϴ�.

set �ڷᱸ���� �̿��Ͽ� �ߺ��� ���ڸ� �����Ͽ����ϴ�.

*/


int dx[4] = {0,0,1,-1}; // �����¿� ���� ��Ÿ ��
int dy[4] = {1,-1,0,0};
char map[4][4]; // 4x4 ũ���� ������ ������ ������ 2���� �迭
set<string> s; // ������� 7�ڸ� ���ڸ� ������ set �ڷᱸ��

// DFS �˰����� �̿��Ͽ� �����ǿ��� 7�ڸ� ���� �����
void DFS(int x, int y, int cnt, string num) {
    // 7�ڸ� ���ڸ� ������ٸ� set�� �߰��ϰ� �Լ� ����
    if (cnt == 7) {
        s.insert(num);
        return;
    }

    // �����¿� �������� Ž��
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // ������ ������ ����� continue
        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;

        // ���� ��ġ�� ���ڸ� �߰��Ͽ� ���� ��ġ�� DFS Ž�� ����
        DFS(nx, ny, cnt + 1, num + map[nx][ny]);
    }
}

int main() {
    int T; // �׽�Ʈ ���̽��� ����
    cin >> T;

    for (int t = 1; t <= T; t++) {
        // set �ڷᱸ�� �ʱ�ȭ
        s.clear();

        // ������ ���� �Է� �ޱ�
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> map[i][j];
            }
        }

        // ��� ��ġ���� DFS Ž�� ����
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                DFS(i, j, 0, "");
            }
        }

        // ������� 7�ڸ� ������ ���� ���
        cout << "#" << t << " " << s.size() << endl;
    }

    return 0;
}