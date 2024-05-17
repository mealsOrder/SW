#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int MAX = 51; // �ִ� �迭 ũ�� ��� ����

int map[MAX][MAX]; // ���� ������ ������ 2���� �迭
bool visited[MAX][MAX]; // �湮 ���θ� ������ 2���� �迭
int M, N, K; // ���� ũ��� ���� ��ġ�� ����
int dx[4] = {0,0,1,-1}; // �����¿� ���� ��Ÿ ��
int dy[4] = {1,-1,0,0};
vector<int> res; // �� ���� ũ�⸦ ������ ����
queue<pair<int,int>> q; // BFS Ž���� ���� ť

// BFS �˰����� �̿��Ͽ� ���� ũ�� ���
void BFS(int x, int y) {
    visited[x][y] = true; // ���� ��ġ �湮 ó��
    q.push({x, y}); // ���� ��ġ�� ť�� ����
    int cnt = 1; // ���� ũ�⸦ ��Ÿ���� ����

    while(!q.empty()) { // ť�� �� ������ �ݺ�
        int curX = q.front().first; // ���� ����� x��ǥ
        int curY = q.front().second; // ���� ����� y��ǥ
        q.pop(); // ���� ��� ť���� ����

        // �����¿� �������� Ž��
        for(int i=0; i<4; i++) {
            int nx = curX + dx[i]; // ���� x��ǥ
            int ny = curY + dy[i]; // ���� y��ǥ

            // ���� ��ǥ�� �� ���� ���̰�, ���߰� ������, ���� �湮���� ���� ���
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true; // ���� ��ǥ �湮 ó��
                q.push({nx, ny}); // ���� ��ǥ�� ť�� ����
                cnt++; // ���� ũ�� ����
            }
        }
    }

    res.push_back(cnt); // ���� ���� ũ�⸦ ��� ���Ϳ� �߰�
}

int main() {
    int T; // �׽�Ʈ ���̽��� ����
    cin >> T;

    for(int t=0; t<T; t++) {
        cin >> M >> N >> K; // ���� ũ��� ���� ��ġ�� ���� �Է� �ޱ�
        memset(map, 0, sizeof(map)); // ���� ���� �ʱ�ȭ
        memset(visited, false, sizeof(visited)); // �湮 ���� �ʱ�ȭ
        res.clear(); // ��� ���� �ʱ�ȭ

        // ���� ��ġ �Է� �ޱ�
        for(int i=0; i<K; i++) {
            int a, b;
            cin >> a >> b;
            map[b][a] = 1; // ���߰� �ִ� ��ġ�� 1�� ǥ��
        }

        // ��� ��ġ���� BFS Ž�� ����
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(map[i][j] && !visited[i][j]) {
                    BFS(i, j);
                }
            }
        }

        // ��� ���
        cout << res.size() << endl;
    }

    return 0;
}