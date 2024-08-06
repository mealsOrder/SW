#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // 숫자 갯수, 현재 숫자, 현재 인덱스
    int N,num=1,idx=0;
    // 갯수 입력
    cin >> N;

    stack<int>s;        // 스택 선언
    vector<int>arr(N);  // 배열 선언
    string res="";      // 결과값을 문자열에 누적
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    while(true){
        // 스택이 비어있거나 최상단 값이 배열의 현재 값보다 작으면
        if(s.empty() || s.top() < arr[idx]) {
            s.push(num++);  // 현재 숫자 푸시하고 1증가
            res += '+';     // 문자열에 + 추가
        }
        // 스택의 최상단 값이 배열의 현재 값과 일치하면
        else if(s.top() == arr[idx]) {
            s.pop();        // 스택에 있는 숫자 팝
            res += '-';     // 문자열에 - 추가
            idx++;          // 현재 인덱스 증가
        }else{
            cout << "NO\n"; // 위 경우가 아니면 불가능한 경우로 NO출력하고
            return 0;       // 프로그램 종료
        }
        // N개의 숫자를 처리하기 위해서는
        // 2*N 개의 연산이 진행되는데 
        // 문자열의 길이가 2N 이 되면 연산 완료이므로 루프 탈출
        if(res.length() == N*2) break;
    }

    // 문자열 출력
    for (char c:res) {
        cout << c << '\n';
    }

    return 0;
}
