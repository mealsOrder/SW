#include<iostream>  
#include<vector>     
#include<algorithm> 
#include<cstring>   

using namespace std;

/*
�� �ڵ�� �̺� �׷��������� �ذ��ϴ� ���Դϴ�. 
�׷����� �������� �� ���� ����� ĥ�� �� �ִ��� ���θ� �Ǵ��ϴ� �����Դϴ�.

DFS�˰����� ����Ͽ� �׷����� Ž���ϸ鼭 
�� ������ RED �Ǵ� BLUE ������ �����մϴ�. 
������ �������� ���� �ٸ� ������ �������� �մϴ�. 
���� ������ �������� ������ ���ٸ� �̺� �׷����� �ƴ� ������ �Ǵ��մϴ�.

�׷��� ������ �湮 ���� �ʱ�ȭ
��� ������ ���� DFS Ž�� ����
���� �������� ���� �˻縦 ���� �̺� �׷��� ���� �Ǵ�
�̺� �׷��� ���� ���
�� �ڵ�� O(V+E)�� �ð� ���⵵�� ������ �ֽ��ϴ�.
*/

const int MAX = 20001; // ������ �ִ� ���� ��� ����
const int RED = 1;     // ������ RED ���� ��� ����
const int BLUE = 2;    // ������ BLUE ���� ��� ����

int V, E;              // ������ ������ ������ ������ ������ ����
vector<int> v[MAX];    // �׷��� ������ ������ ���� ����Ʈ �迭
int visited[MAX];      // �� ������ �湮 ���¿� ���� ������ ������ �迭

// DFS �˰����� �̿��� �׷����� Ž���ϰ� ������ ������ ĥ�ϴ� �Լ�
void DFS(int x, int color) {
    visited[x] = color;  // ���� ���� x�� ������ ����

    // ���� ���� x�� ����� ��� ���� ���� nx�� ����
    for (int i = 0; i < v[x].size(); i++) {
        int nx = v[x][i];

        // ���� �湮���� ���� �����̶��
        if (!visited[nx]) {
            // ���� ������ �ݴ� ����� ĥ�ϸ� DFS Ž�� ����
            DFS(nx, 3 - color);
        }
    }
}

int main() {
    int T;  // �׽�Ʈ ���̽��� ������ ������ ����

    // �׽�Ʈ ���̽��� ���� �Է� �ޱ�
    cin >> T;

    for (int t = 1; t <= T; t++) {
        // ������ ������ ������ ���� �Է� �ޱ�
        cin >> V >> E;

        // �׷��� ������ �湮 ���� �ʱ�ȭ
        for (int i = 1; i <= V; i++) v[i].clear();
        memset(visited, 0, sizeof(visited));

        // ���� ���� �Է� �ޱ�
        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        // ��� ������ ���� DFS Ž�� ����
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                DFS(i, RED);  // ù ��° ������ RED�� ĥ��
            }
        }

        // �̺� �׷��� �Ǵ�
        bool isBigraph = true;
        for (int i = 1; i <= V; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                int next = v[i][j];
                // ������ ������ ������ ���ٸ� �̺� �׷����� �ƴ�
                if (visited[i] == visited[next]) {
                    isBigraph = false;
                    break;
                }
            }
            if (!isBigraph) break;
        }

        // �̺� �׷��� ���� ���
        if (isBigraph) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}