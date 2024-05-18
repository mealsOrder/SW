#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string first; // 입력받은 문자열
int N; // 교환할 횟수
int ans; // 최종 결과 값

// DFS (Depth-First Search) 알고리즘을 이용하여 최대값 찾기
void DFS(int idx, int cnt) {
    // 교환 횟수가 N과 같아지면 (즉, 교환이 완료되면)
    if (cnt == N) {
        // 현재 문자열을 정수로 변환하여 최대값과 비교
        int num = stoi(first);
        if (num > ans) ans = num;
        return;
    }

    // 문자열 내의 모든 자리수 쌍에 대해 교환을 시도
    for (int i = idx; i < first.size(); i++) {
        for (int j = i + 1; j < first.size(); j++) {
            // 두 자리수가 오름차순이 아닌 경우 교환
            if (first[i] <= first[j]) {
                // 두 자리수 교환
                int temp = first[i];
                first[i] = first[j];
                first[j] = temp;

                // 교환 후 DFS 호출
                DFS(i, cnt + 1);

                // 교환 전 상태로 복구
                temp = first[i];
                first[i] = first[j];
                first[j] = temp;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        // 입력 받기
        cin >> first >> N;

        // 초기화
        ans = stoi(first);
        DFS(0, 0);

        // 결과 출력
        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}