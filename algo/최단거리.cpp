#include <iostream>
#include <vector>
#include <climits> // �ڷ����� �ִ밪�� �ּҰ��� �����ϴ� ���

using namespace std;

const int MAX = 10000;
const int INF = INT_MAX; // INT_MAX �̰��� ����ϱ� ���� climits ��� ���
vector<int> graph[MAX]; // �׷��� ���� ����
int dist[MAX]; // ����������� �ִ� �Ÿ�
bool visited[MAX]; // �湮 ����
int N, M;

// ���ͽ�Ʈ�� �˰����� ����Ͽ� start �������������� �ִ� �Ÿ��� ����ϴ� �Լ�
void dijkstra(int start) {
    // dist �迭�� �ִ밪(���Ѵ�)���� �ʱ�ȭ
    fill(dist, dist + MAX, INF);
    dist[start] = 0; // ���� ������ �Ÿ��� 0���� ����

    // �������� �湮���� ���� ���·� �ʱ�ȭ
    fill(visited, visited + MAX, false);

    for (int i = 0; i < MAX; i++) {
        int min_dist = INF;
        int cur_node = -1;

        // ���� �湮���� ���� ���� �߿��� �ִ� �Ÿ��� ���� ������ ã��
        for (int j = 0; j < MAX; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                cur_node = j;
            }
        }

        // ��� ������ �湮�߰ų� �ִ� �Ÿ��� ���� ������ ���� ��� ����
        if (cur_node == -1) break;

        visited[cur_node] = true; // ���� ������ �湮 ǥ��

        // ���� �������� ����� �� ���������� �ִ� �Ÿ��� ����
        for (auto next : graph[cur_node]) {
            int next_node = next;
            int next_dist = 1 + dist[cur_node]; // ������ ����ġ�� ��� 1�� ����

            // ���� ���������� �Ÿ��� ���� ����� �Ÿ����� ���� ��� ����
            if (next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
            }
        }
    }
}

int main() {
 
    cin >> N >> M; // ������ �� N�� ������ �� M�� �Է� ����

    // ���� ������ �Է� �޾� �׷����� ����
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // ����� �׷����̹Ƿ� �������� ����

        // 

    }

    int start, end;
    cin >> start >> end; // ������� �������� �Է� ����

    dijkstra(start); // ���ͽ�Ʈ�� �˰����� ����Ͽ� �ִ� �Ÿ� ���

    cout << dist[end] << endl; // ������������ �ִ� �Ÿ� ���

    return 0;
}