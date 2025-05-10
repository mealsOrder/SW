#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;
        string S;
        cin >> S;

        vector<pair<int, int>> ops;

        // 올바른 괄호 문자열은 '(' * N + ')' * N 의 정렬된 형태
        string target = string(N,'(') + string(N, ')');

        // 현재 문자열 S와 target을 비교하면서 정렬
        int l = 0, r = 2 * N - 1;
        while(l < r) {
            // 앞에서부터 mismatch 찾기
            while(l < 2 * N && S[l] == target[l]) l++;
            // 뒤에서부터 mismatch 찾기
            while(r > l && S[r] == target[r]) r--;

            if(l < r) {
                // 뒤집기
                reverse(S.begin() + l, S.begin() + r + 1);
                ops.push_back({l + 1, r + 1}); // 1-based
                l++; r--;
            }
        }

        cout << ops.size() << '\n';
        for(auto [l, r] : ops)
            cout << l << ' ' << r << '\n';
    }

    return 0;
}
