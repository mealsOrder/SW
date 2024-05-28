#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 최대공약수(GCD: Greatest Common Divisor) 구하는 함수
int findGCD(int a, int b) {
    // 유클리드 호제법을 이용하여 GCD 계산
    int remainder = a % b;
    while (remainder != 0) {
        a = b;
        b = remainder;
        remainder = a % b;
    }
    return b;
}

int main() {
    int numA, numB; // 두 수를 저장할 변수

    // 두 수 입력받기
    cin >> numA >> numB;

    int GCD = 0; // 최대공약수를 저장할 변수
    if (numA >= numB) { // 큰 수가 numA라면
        GCD = findGCD(numA, numB); // numA와 numB의 GCD 계산
    } else { // numB가 더 크다면
        GCD = findGCD(numB, numA); // numB와 numA의 GCD 계산
    }

    int LCM = numA * numB / GCD; // 최소공배수 계산

    // GCD와 LCM 출력
    cout << GCD << '\n' << LCM;
    return 0;
}