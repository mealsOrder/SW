#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MX = 1000001;

int arr[MX];     // 입력 수열
int dp[MX];      // 메모이제이션
int cho[MX];     // 경로 추적 (선택된 다음 인덱스)
int N;

// 최장 증가 부분 수열의 길이 계산
int func(int start){
    int& ret = dp[start + 1];
    if (ret != -1) return ret;

    ret = 1; // 최소 길이 = 자기 자신 포함
    int bestNx = -1;

    for (int next = start + 1; next < N; next++) {
        if (start == -1 || arr[start] < arr[next]) {
            int cand = func(next) + 1;
            if (cand > ret) {
                ret = cand;
                bestNx = next;
            }
        }
    }

    cho[start + 1] = bestNx; // 다음 경로 저장
    return ret;
}

// 최장 증가 부분 수열 재구성
void reconstruct(int start, vector<int>& seq) {
    if (start != -1) seq.push_back(arr[start]);
    int nx = cho[start + 1];
    if (nx != -1) reconstruct(nx, seq);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    memset(dp, -1, sizeof(dp));
    memset(cho, -1, sizeof(cho));

    int lisLen = func(-1) - 1; // func(-1)은 1이 더해져 있음 → 빼줌
    vector<int> seq;
    reconstruct(-1, seq);

    cout << lisLen << '\n';
    for (int x : seq) cout << x << ' ';
    cout << '\n';

    return 0;
}
