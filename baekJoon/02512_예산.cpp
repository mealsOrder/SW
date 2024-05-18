#include <iostream>
#include <algorithm>
using namespace std;

/*

budgets �迭�� ������������ �����մϴ�.
�̺� Ž���� �����Ͽ� �ִ� ���� �ݾ��� ã���ϴ�.
�߰��� mid�� ����մϴ�.
�Լ��� ȣ���Ͽ� �߰��� mid�� �������� �� �� �� ���� ���� ����մϴ�.
�� ���� ���� M �����̸� ���� �� �� �����Ƿ� 
answer�� mid�� �����ϰ� left�� mid+1�� �ű�
�� ���� ���� M�� �ʰ��ϸ� right�� mid-1�� �ű�
�̺� Ž���� ������ ���� ���� answer�� ����մϴ�.
�Լ��� �߰��� mid�� �������� �� �� �� ���� ���� ����ϴ� ������ �մϴ�. 
�� ������ ���� ��û �ݾ��� mid�� �ʰ��ϴ� ��� mid�� �����ϰ�, 
�׷��� ���� ��� ���� ���� ��û �ݾ��� ����մϴ�.

�̷��� �̺� Ž�� ����� ����ϸ� ȿ�������� �ִ� ���� �ݾ��� ã�� �� �ֽ��ϴ�. 
�ð� ���⵵�� O(N log N)�Դϴ�.

*/


long long N, M; // N: ������ ��, M: �� ����
long long budgets[10000]; // �� ������ ���� ��û �ݾ�

long long findMaxSum(long long limit) {
    long long sum = 0;
    for (long long i = 0; i < N; i++) {
        if (budgets[i] <= limit) {
            sum += budgets[i];
        } else {
            sum += limit;
        }
    }
    return sum;
}

int main() {
    // N: ������ �� �Է�
    cin >> N;
    for (long long i = 0; i < N; i++) {
        // �� ������ ���� ��û �ݾ� �Է�
        cin >> budgets[i];
    }
    // M: �� ���� �Է�
    cin >> M;

    // ������ ���� ��û �ݾ��� ������������ ����
    sort(budgets, budgets + N);

    // �̺� Ž���� ���� �ʱⰪ ����
    long long left = 1, right = budgets[N - 1];
    long long answer = 0;

    // �̺� Ž�� ����
    while (left <= right) {
		cout << left << " " << right << '\n';
        long long mid = (left + right) / 2; // �߰��� ���
        long long sum = findMaxSum(mid); // �߰����� �������� �� ���� �� ���
		cout << "�߰���: " << sum << endl;
        if (sum <= M) { // �� ���� ���� M ������ ���
            answer = mid; // ���� �� �� �����Ƿ� answer ����
            left = mid + 1; // �� ū ���� ã�� ���� left�� mid+1�� �̵�
        } else { // �� ���� ���� M�� �ʰ��ϴ� ���
            right = mid - 1; // �� ���� ���� ã�� ���� right�� mid-1�� �̵�
        }
    }

    // ���� �� ���
    cout << answer << endl;
    return 0;
}