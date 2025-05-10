#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 5001;

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> cnt(MAX, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        cnt[A[i]]++;
    }

    int answer = 0;

    for (int g1 = 1; g1 < MAX; ++g1) {
        int cnt_g1 = 0;
        for (int i = g1; i < MAX; i += g1) {
            cnt_g1 += cnt[i];
        }

        if (cnt_g1 == 0) continue;

        int g2 = 0;
        for (int i = 1; i < MAX; ++i) {
            if (i % g1 != 0 && cnt[i] > 0) {
                for (int k = 0; k < cnt[i]; ++k) {
                    g2 = gcd(g2, i);
                    if (g2 == 1) break;
                }
            }
            if (g2 == 1) break;
        }

        answer = max(answer, g1 + g2);
    }

    // 모든 S' = ∅ 또는 전체가 되는 경우도 고려해야 함
    int all_gcd = A[0];
    for (int i = 1; i < N; ++i)
        all_gcd = gcd(all_gcd, A[i]);
    answer = max(answer, all_gcd); // gcd(S') + gcd(∅) = all_gcd + 0

    cout << answer << '\n';
    return 0;
}
