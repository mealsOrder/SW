#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


/* BFS 사용하여 이상한 계산기로 숫자 N을 만들기 위한 최소 버튼 클릭 횟수를 찾는 것.

(1)초기값 1과 버튼 클릭 횟수 0을 큐에 추가하고 visited[1]을 true로 설정하여 방문 처리합니다.
(2)큐가 빌 때까지 반복합니다.
(3)각 반복 단계에서 큐의 크기만큼 반복하며, 현재 값과 버튼 클릭 횟수를 추출합니다.
(4)현재 값이 N과 같으면 버튼 클릭 횟수를 반환합니다.
(5)현재 값이 5자리를 넘어가면 더 이상 탐색하지 않습니다.
(6)현재 값을 2배로 만들 수 있고, 방문하지 않은 경우 큐에 추가하고 방문 처리합니다.
(7)현재 값을 3으로 나눌 수 있고, 방문하지 않은 경우 큐에 추가하고 방문 처리합니다.
(8)큐가 비어있으면 더 이상 계산이 불가능한 경우이므로 -1을 반환합니다.

*/


const int MAX = 100001; // 계산기의 최대 출력값

// 현재 값과 버튼 클릭 횟수를 저장하는 큐
queue<pair<int, int>> q; // cur,cnt
bool visited[MAX]; // 방문 기록을 저장하는 배열
int res; // 최종 결과

int BFS(int N) {
    // 초기화
    visited[1] = true; // 초기값 1을 방문 처리
    q.push({1, 0}); // 초기값 1과 버튼 클릭 횟수 0을 큐에 추가

    while (!q.empty()) { // 큐가 빌 때까지 반복
        for (int i = 0; i < q.size(); i++) { // 현재 큐의 크기만큼 반복
            int cur = q.front().first; // 현재 값 추출
            int cnt = q.front().second; // 현재 버튼 클릭 횟수 추출
            q.pop(); // 큐에서 현재 값 제거

            if (cur == N) return cnt; // 현재 값이 N과 같으면 버튼 클릭 횟수 반환

            if (cur > 99999) continue; // 현재 값이 5자리를 넘어가면 더 이상 탐색하지 않음

            // 현재 값을 2배로 만들 수 있고, 방문하지 않은 경우 큐에 추가
            if (cur * 2 <= 99999 && !visited[cur * 2]) {
                visited[cur * 2] = true;
                q.push({cur * 2, cnt + 1});
            }
            // 현재 값을 3으로 나눌 수 있고, 방문하지 않은 경우 큐에 추가
            if (cur / 3 >= 1 && !visited[cur / 3]) {
                visited[cur / 3] = true;
                q.push({cur / 3, cnt + 1});
            }
        }
    }

    return -1; // 더 이상 계산이 불가능한 경우 -1 반환
}

int main() {
    int N;
    cin >> N;

    res = BFS(N);

    cout << res << endl;

    return 0;
}