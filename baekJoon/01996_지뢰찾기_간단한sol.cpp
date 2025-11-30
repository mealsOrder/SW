#include <iostream>
using namespace std;

const int MAX = 100;
char map[MAX][MAX];
int result[MAX][MAX];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> map[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '.') continue;

            int minePower = map[i][j] - '0';
            for (int d = 0; d < 8; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < N && nj >= 0 && nj < N && map[ni][nj] == '.')
                    result[ni][nj] += minePower;
            }
        }
    }

    // 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] != '.') cout << '*';
            else if (result[i][j] >= 10) cout << 'M';
            else cout << result[i][j];
        }
        cout << '\n';
    }

    return 0;
}