#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/**
 * @brief 시간초과 해결한 코드
 * 
 * @param from 
 * @param to 
 * @param M 
 * @return int 
 */
int clockwise_distance(int from, int to, int M) {
    return (to - from + M) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N, M;
        cin >> N >> M;

        vector<int> A(N);
        unordered_map<int, int> idx_map; // 번호 → 인덱스
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            idx_map[A[i]] = i;
        }

        // 1. 전체 거리 구하기
        vector<int> dist(N - 1);
        int total = 0;
        for (int i = 0; i < N - 1; ++i) {
            dist[i] = clockwise_distance(A[i], A[i + 1], M);
            total += dist[i];
        }

        int answer = total;

        // 2. 1~M 번호 중 하나씩 제거해보며 최솟값 갱신
        for (int banned = 1; banned <= M; ++banned) {
            // 해당 번호가 A에 없다면 그냥 그대로
            if (idx_map.find(banned) == idx_map.end()) {
                answer = min(answer, total);
                continue;
            }

            int i = idx_map[banned];
            int new_total = total;

            if (N == 1) {
                // 방문 숫자 하나밖에 없는데 그걸 지우면 거리 0
                answer = 0;
                continue;
            }

            if (i == 0) {
                // 시작 번호 제거 → A[1]부터 시작
                new_total -= dist[0];
            } else if (i == N - 1) {
                // 마지막 번호 제거 → 마지막 거리 제거
                new_total -= dist[N - 2];
            } else {
                // 중간 번호 제거 → A[i-1] → A[i+1] 로 교체
                int remove_dist = dist[i - 1] + dist[i];
                int new_dist = clockwise_distance(A[i - 1], A[i + 1], M);
                new_total = total - remove_dist + new_dist;
            }

            answer = min(answer, new_total);
        }

        cout << "#" << t << " " << answer << '\n';
    }

    return 0;
}
