#include <iostream>
using namespace std;

int main() {
    int n;
    int result = -1, rNum = 0;
    int a[1005][5];

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;

        for (int j = 1; j <= n; j++) {
            if (i == j) continue;

            if (a[i][0] == a[j][0] ||
                a[i][1] == a[j][1] ||
                a[i][2] == a[j][2] ||
                a[i][3] == a[j][3] ||
                a[i][4] == a[j][4]) {
                cnt++;
            }
        }

        if (result < cnt) {
            result = cnt;
            rNum = i;
        }
    }

    cout << rNum << endl;

    return 0;
}