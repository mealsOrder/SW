#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MX = 100001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // 숫자 갯수, 시작숫자, 현재 위치
    int N, num = 1, cur = 0;
    cin >> N;

    // 백터 배열
    vector<int> arr(N);

    // 배열 입력받음
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    stack<int> s; // 스택 선언
    string res="";   // 결과 출력용 문자열

    // 무한 반복 
    while (true) {
        // 스택이 비어있거나
        // 최상단의 값이 현 위치의 값보다 작다면
        
        if (s.empty() || s.top() < arr[cur]) {
            s.push(num++);// 숫자를 스택에 푸시하고 숫자 1증가
            res += '+'; // 결과문자열에 +추가
        } 
        // 최상단 값이 현위치의 값과 같다면
        else if (s.top() == arr[cur]) {
            s.pop();    // 최상단 값 스택에서 빼내고
            res += '-'; // 결과 문자열에 -추가
            cur++;      // 현위치 증가
        } else {        // 그게 아니라면 안되는 경우로 NO출력
            cout << "NO\n";
            return 0;   // 프로그램 정상 종료
        }
        // 연산의 개수가 2N개라면 종료
        // 결과 문자열의 길이는 
        // 넣는 연산 N번 + 빼는 연산 N번 해서 총 2N번임
        if (res.length() == N * 2) break;
    }

    // res문자열 순회하면서 한글자씩 출력
    for (char c : res) {
        cout << c << '\n';
    }

    return 0;
}