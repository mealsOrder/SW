#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MX = 20001;

/**
 * @brief 시간초과 나는 코드
 * 
 * @param from 
 * @param to 
 * @param M 
 * @return int 
 */

// 시계방향 거리 계산
int clockwise_distance(int from, int to, int M) {
    return (to - from + M) % M;
}

// banned 번호를 제외하고 실제 시작점부터 계산
int simulate(const vector<int>& A, int banned, int M) {
    vector<int> path;
    for (int a : A) {
        if (a != banned)
            path.push_back(a);
    }

    if (path.empty()) return 0; // 방문할 곳이 없음

    int cur = path[0]; // 출발점을 path의 첫 번째로
    int total = 0;
    for (int i = 1; i < path.size(); ++i) {
        total += clockwise_distance(cur, path[i], M);
        cur = path[i];
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++) {
        int N, M;
        cin >> N >> M;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        int answer = 1e9;

        // 아무것도 제외하지 않은 경우
        int d = 0;
        int cur = A[0];
        for (int i = 1; i < N; ++i) {
            d += clockwise_distance(cur, A[i], M);
            cur = A[i];
        }
        answer = d;
        cout << d << ' ';
        // 각 번호를 하나씩 제외
        for (int banned = 1; banned <= M; ++banned) {
            int cost = simulate(A, banned, M);
            cout << cost << ' ';
            answer = min(answer, cost);
        }

        cout << "#" << t << " " << answer << '\n';
    }

    return 0;
}
