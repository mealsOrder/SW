#include <iostream>
#include <cstring>
using namespace std;

int T, N; // �׽�Ʈ ���̽� ���� N-Queen ������ ũ��
int board[15]; // �� ���� ���� �� ��ġ�� ����
int count; // ����� ��

// ���� ���� ���� ���� ����� ����� �浹�ϴ��� Ȯ���ϴ� �Լ�
bool isValid(int x) {
    for (int i = 0; i < x; i++) {
        // ���� �� �Ǵ� �밢���� ���� �ִ� ��� false ��ȯ
        if (board[i] == board[x] || abs(board[i] - board[x]) == x - i)
            return false;
    }
    // �浹�� ���� ��� true ��ȯ
    return true;
}

// ��Ʈ��ŷ�� ���� N-Queen ������ �ذ��ϴ� �Լ�
void backtrack(int x) {
    if (x == N) { // N���� ���� ��� ��ġ�� ���
        count++; // ����� �� ����
        return;
    }

    for (int j = 0; j < N; j++) { // �� ���� �˻�
        board[x] = j; // ���� ���� ���� j���� ��ġ
        if (isValid(x)) // ���� ���� �浹���� ������
            backtrack(x + 1); // ���� ������ ����
    }
}

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        count = 0;
        memset(board, 0, sizeof(board)); // �ʱ�ȭ
        backtrack(0); // ��Ʈ��ŷ ����
        cout << "#" << tc << " " << count << "\n";
    }
    return 0;
}