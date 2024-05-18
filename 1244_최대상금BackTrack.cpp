#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string first;
        int N;
        cin >> first >> N;

        int maxNum = stoi(first);

        if (N == 0) {
            cout << "#" << t << " " << maxNum << endl;
            continue;
        }

        for (int i = first.size() - 1; i > 0 && N > 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if (first[i] < first[j]) {
                    swap(first[i], first[j]);
                    int curNum = stoi(first);
                    if (curNum > maxNum) {
                        maxNum = curNum;
                    }
                    N--;
                    if (N == 0) {
                        break;
                    }
                    swap(first[i], first[j]);
                }
            }
        }

        cout << "#" << t << " " << maxNum << endl;
    }

    return 0;
}