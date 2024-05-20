#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int first = 1;
    int nf = 0;
    int num = 1;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            num = num + cnt;
            cout << num << " ";
            cnt++;
        }
        first = first + i;
        num = first;
        cout << endl;
        cnt = i;
    }

    return 0;
}