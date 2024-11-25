#include <iostream> // 표준 입출력 라이브러리
#include <iomanip>  // 출력 형식 설정 (소수점 자리수 조정 등)
#include <vector>   // 동적 배열을 위한 벡터 라이브러리
#include <cmath>    // 수학 함수 라이브러리 (예: pow, sqrt 등)

using namespace std;

// 절대적 안전 거리(S_abs)를 계산하는 함수
// 매개변수:
// SE - 정지 상태 최소 거리 (m)
// Vp1 - 후속 차량의 초기 속도 (m/s)
// tr - 운전자의 반응 시간 (s)
// to - 제동 활성화 지연 시간 (s)
// tn - 압력 증가 시간 (s)
// ah1 - 후속 차량의 감속도 (m/s^2)
double calculateAbsoluteSafeDistance(double SE, double Vp1, double tr, double to, double tn, double ah1) {
    return SE + Vp1 * (tr + to + tn / 2.0) + (Vp1 * Vp1) / (2.0 * ah1);
}

// 상대적 안전 거리(S_rel)를 계산하는 함수
// 매개변수:
// S_abs - 절대적 안전 거리 (m)
// Vp1 - 후속 차량의 초기 속도 (m/s)
// ah2 - 선행 차량의 감속도 (m/s^2)
double calculateRelativeSafeDistance(double S_abs, double Vp1, double ah2) {
    return S_abs - (Vp1 * Vp1) / (2.0 * ah2);
}

// 2초 규칙 기반 거리(S_2s)를 계산하는 함수
// 매개변수:
// Vp1 - 후속 차량의 초기 속도 (m/s)
double calculateTwoSecondDistance(double Vp1) {
    return 2.0 * Vp1;
}

// 속도의 50% 거리(S_50%)를 계산하는 함수
// 매개변수:
// Vp1 - 후속 차량의 초기 속도 (m/s)
double calculateFiftyPercentDistance(double Vp1) {
    return 0.5 * Vp1;
}

int main() {
    // 초기 매개변수 설정
    double SE = 0.0; // 정지 상태에서의 최소 거리 (m)
    double tr[] = {0.74, 0.85, 1.10, 1.41, 1.73, 1.99}; // 운전자 반응 시간의 분위수 배열
    double to = 0.5; // 제동 활성화 지연 시간 (s)
    double tn = 0.2; // 압력 증가 시간 (s)
    double ah1 = 9.0; // 후속 차량의 감속도 (m/s^2)
    double ah2 = 9.0; // 선행 차량의 감속도 (m/s^2)

    // 초기 속도 범위를 설정 (km/h 단위)
    vector<double> speeds; // 속도를 저장할 벡터
    for (double speed = 0; speed <= 200; speed += 10) {
        speeds.push_back(speed); // 0~200km/h 범위를 10km/h 간격으로 설정
    }

    // 결과 출력 형식 설정
    cout <<  fixed <<  setprecision(2); // 소수점 2자리로 출력
    cout << "Speed(km/h)\tS_abs(m)\tS_rel(m)\tS_2s(m)\tS_50%(m)\n";

    // 각 분위수(BRT 값)에 대해 반복 수행
    for (size_t i = 0; i < 6; ++i) { // 분위수 배열은 6개의 값 (10%, 25%, Median, 75%, 90%, 99%)
        cout << "\nBRT Quantile: " << (i + 1) * 10 << "%\n"; // 분위수 표시
        for (double speed : speeds) { // 각 초기 속도에 대해 계산
            double Vp1 = speed * 1000.0 / 3600.0; // 속도를 km/h에서 m/s로 변환
            // 각 안전 거리 계산
            double S_abs = calculateAbsoluteSafeDistance(SE, Vp1, tr[i], to, tn, ah1); // 절대적 안전 거리
            double S_rel = calculateRelativeSafeDistance(S_abs, Vp1, ah2);             // 상대적 안전 거리
            double S_2s = calculateTwoSecondDistance(Vp1);                             // 2초 규칙 거리
            double S_50 = calculateFiftyPercentDistance(Vp1);                          // 50% 거리

            // 결과 출력
            cout << speed << "\t\t" << S_abs << "\t\t" << S_rel << "\t\t" << S_2s << "\t\t" << S_50 << "\n";
        }
    }

    return 0;
}
