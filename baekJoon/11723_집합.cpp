#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(NULL); // 입출력 속도 향상
    cout.tie(NULL); // 입출력 속도 향상

    int M; // 수행할 연산의 수
    cin >> M;

    int S = 0; // 비트마스크로 표현된 집합
    while (M--) {
        string cmd; // 명령어
        cin >> cmd;

        if (cmd == "add") {
            int x; // 추가할 원소
            cin >> x;
            S |= (1 << (x - 1)); // 원소 추가
        } else if (cmd == "remove") {
            int x; // 제거할 원소
            cin >> x;
            S &= ~(1 << (x - 1)); // 원소 제거
        } else if (cmd == "check") {
            int x; // 확인할 원소
            cin >> x;
            cout << ((S & (1 << (x - 1))) ? 1 : 0) << '\n'; // 원소 확인
        } else if (cmd == "toggle") {
            int x; // 토글할 원소
            cin >> x;
            S ^= (1 << (x - 1)); // 원소 토글
        } else if (cmd == "all") {
            S = (1 << 20) - 1; // 모든 원소 추가
        } else if (cmd == "empty") {
            S = 0; // 모든 원소 제거
        }
    }

    return 0;
}
