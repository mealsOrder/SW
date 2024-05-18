#include <iostream>
#include <algorithm>
using namespace std;

/*

budgets 배열을 오름차순으로 정렬합니다.
이분 탐색을 수행하여 최대 지원 금액을 찾습니다.
중간값 mid를 계산합니다.
함수를 호출하여 중간값 mid를 기준으로 할 때 총 예산 합을 계산합니다.
총 예산 합이 M 이하이면 답이 될 수 있으므로 
answer를 mid로 갱신하고 left를 mid+1로 옮김
총 예산 합이 M을 초과하면 right를 mid-1로 옮김
이분 탐색이 끝나면 최종 답인 answer를 출력합니다.
함수는 중간값 mid를 기준으로 할 때 총 예산 합을 계산하는 역할을 합니다. 
각 지방의 예산 요청 금액이 mid를 초과하는 경우 mid로 제한하고, 
그렇지 않은 경우 실제 예산 요청 금액을 사용합니다.

이러한 이분 탐색 기법을 사용하면 효율적으로 최대 지원 금액을 찾을 수 있습니다. 
시간 복잡도는 O(N log N)입니다.

*/


long long N, M; // N: 지방의 수, M: 총 예산
long long budgets[10000]; // 각 지방의 예산 요청 금액

long long findMaxSum(long long limit) {
    long long sum = 0;
    for (long long i = 0; i < N; i++) {
        if (budgets[i] <= limit) {
            sum += budgets[i];
        } else {
            sum += limit;
        }
    }
    return sum;
}

int main() {
    // N: 지방의 수 입력
    cin >> N;
    for (long long i = 0; i < N; i++) {
        // 각 지방의 예산 요청 금액 입력
        cin >> budgets[i];
    }
    // M: 총 예산 입력
    cin >> M;

    // 지방의 예산 요청 금액을 오름차순으로 정렬
    sort(budgets, budgets + N);

    // 이분 탐색을 위한 초기값 설정
    long long left = 1, right = budgets[N - 1];
    long long answer = 0;

    // 이분 탐색 수행
    while (left <= right) {
		cout << left << " " << right << '\n';
        long long mid = (left + right) / 2; // 중간값 계산
        long long sum = findMaxSum(mid); // 중간값을 기준으로 총 예산 합 계산
		cout << "중간합: " << sum << endl;
        if (sum <= M) { // 총 예산 합이 M 이하인 경우
            answer = mid; // 답이 될 수 있으므로 answer 갱신
            left = mid + 1; // 더 큰 값을 찾기 위해 left를 mid+1로 이동
        } else { // 총 예산 합이 M을 초과하는 경우
            right = mid - 1; // 더 작은 값을 찾기 위해 right를 mid-1로 이동
        }
    }

    // 최종 답 출력
    cout << answer << endl;
    return 0;
}