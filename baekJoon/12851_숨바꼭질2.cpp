#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100001;

int N, K;            // 수빈 위치, 동생 위치
int t = 0, num = 0;  // 최단 시간, 방법 수
bool visit[MAX];     // 방문 체크

void BFS() {
    queue<pair<int, int>> q; // {위치,시간}
    q.push({N, 0});

    while (!q.empty()) {
        int x = q.front().first;
        int time = q.front().second;
        q.pop();

        visit[x] = true; // 큐에서 꺼낼 때 방문 처리

        if (x == K) {
            if (num == 0) {
                t = time;
                num = 1;
            } else if (time == t) {
                num++;
            }
            continue; // 더 이상 탐색하지 않고 다음 큐 진행
        }

        for (int nx : {x - 1, x + 1, x * 2}) {
            if (nx < 0 || nx >= MAX) continue;

            // 방문하지 않았거나, 동일 시간에 재도달 허용
            if (!visit[nx]) {
                q.push({nx, time + 1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    if (N == K) {
        cout << 0 << '\n' << 1 << '\n';
        return 0;
    }

    BFS();

    cout << t << '\n' << num << '\n';
    return 0;
}
