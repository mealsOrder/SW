#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    // 우선순위 큐를 priorities 벡터로 초기화하여 큰 값부터 나오도록 설정
    priority_queue<int> pq(priorities.begin(), priorities.end());
    int i = 0; // 현재 인덱스
    while (true) {
        // 현재 인덱스의 우선순위가 가장 높은 우선순위와 같은지 확인
        if (priorities[i] == pq.top()) {
            answer++;   // 수 증가
            pq.pop();   // 우선순위 큐에서 해당 우선순위 제거
            // 현재 인덱스가 찾고자 하는 문서의 위치이면 결과 반환
            if (i == location) return answer;
        }
        // 인덱스를 순환시키기 위해 모듈러 연산 사용
        i = (i + 1) % priorities.size();
    }
    return answer;
}
