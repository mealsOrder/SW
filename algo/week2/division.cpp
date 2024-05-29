#include <iostream>
#include <vector>
using namespace std;

vector<int> result(30); // 결과를 저장할 벡터
int n; // 사용자로부터 입력받을 숫자
int cnt; // 가능한 경우의 수를 세는 카운터

// 재귀 함수: 현재까지의 합(mySum)과 현재 인덱스(index)를 인자로 받음
void getResult(int mySum, int index){
    // 기저 조건: 현재까지의 합이 n과 같으면 결과를 출력하고 카운터를 증가시킴
    if(mySum == n){
        cout << result[0];
        for(int i=1; i<index; i++){
            cout << "+" << result[i];
        }
        cout << "\n";
        cnt++;
    }
    else{
        int myNumber;
        // 첫 번째 숫자를 결정하는 경우와 그 외의 경우를 구분
        if(index == 0) myNumber = n-1;
        else myNumber = n-mySum;
        // myNumber부터 1까지 반복
        for(int i=myNumber; i>=1; i--){
            result[index] = i; // 현재 인덱스에 i를 저장
            // 이전 숫자보다 현재 숫자가 크면 건너뜀 (오름차순으로 유지)
            if(index > 0 && result[index-1] < result[index]) continue;
            // 재귀 호출: 현재까지의 합에 i를 더하고, 인덱스를 1 증가시킴
            getResult(mySum+i, index+1);
        }
    }
}

int main() {
    cin >> n;       // 사용자로부터 숫자를 입력받음
    getResult(0,0); // 재귀 함수를 호출 (처음에는 합과 인덱스 모두 0)
    cout << cnt << "\n"; // 가능한 경우의 수를 출력
    return 0;
}
