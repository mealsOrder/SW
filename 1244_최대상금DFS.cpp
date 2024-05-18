#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string first; // �Է¹��� ���ڿ�
int N; // ��ȯ�� Ƚ��
int ans; // ���� ��� ��

// DFS (Depth-First Search) �˰����� �̿��Ͽ� �ִ밪 ã��
void DFS(int idx, int cnt) {
    // ��ȯ Ƚ���� N�� �������� (��, ��ȯ�� �Ϸ�Ǹ�)
    if (cnt == N) {
        // ���� ���ڿ��� ������ ��ȯ�Ͽ� �ִ밪�� ��
        int num = stoi(first);
        if (num > ans) ans = num;
        return;
    }

    // ���ڿ� ���� ��� �ڸ��� �ֿ� ���� ��ȯ�� �õ�
    for (int i = idx; i < first.size(); i++) {
        for (int j = i + 1; j < first.size(); j++) {
            // �� �ڸ����� ���������� �ƴ� ��� ��ȯ
            if (first[i] <= first[j]) {
                // �� �ڸ��� ��ȯ
                int temp = first[i];
                first[i] = first[j];
                first[j] = temp;

                // ��ȯ �� DFS ȣ��
                DFS(i, cnt + 1);

                // ��ȯ �� ���·� ����
                temp = first[i];
                first[i] = first[j];
                first[j] = temp;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        // �Է� �ޱ�
        cin >> first >> N;

        // �ʱ�ȭ
        ans = stoi(first);
        DFS(0, 0);

        // ��� ���
        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}