#include <iostream>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    int space = n - 1, num = 1;
    int preFirst, preLast;

    for (int i = 1; i <= n; i++) {
        // 공백 출력
        for (int j = 0; j < space; j++) {
            cout << " ";
        }
        space--;

        if (i % 2 == 0) { // 짝수줄, 증가하면서 출력
            int curFirst = preFirst + 1;
            if (curFirst >= 10) curFirst = 1;

            for (int j = 0; j < num; j++) {
                cout << curFirst;
                preLast = curFirst;
                curFirst += 1;
                if (curFirst >= 10) {
                    curFirst = 1;
                }
            }
        } else { // 홀수줄, 감소하면서 출력
            int curFirst;

            if (i == 1) curFirst = s;
            else {
                curFirst = preLast;
                for (int j = 0; j < num; j++) {
                    curFirst += 1;
                    if (curFirst >= 10) {
                        curFirst = 1;
                    }
                }
            }

            preFirst = curFirst;

            for (int j = 0; j < num; j++) {
                cout << curFirst;
                curFirst -= 1;
                if (curFirst <= 0) curFirst = 9;
            }
        }
        num += 2;
        cout << endl;
    }

    return 0;
}