#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

// 안전 거리 계산 함수
double calculateSafeDistance(double speed, double reactionTime, double brakingDistance) {
    return speed * reactionTime + brakingDistance;
}

// 사고 확률 계산 함수
double calculateAccidentProbability(double distance, double safeDistance) {
    if (distance < safeDistance) {
        return 1.0; // 사고 발생 확률 100%
    } else {
        return std::max(0.0, 1.0 - (distance - safeDistance) / distance); // 거리 기반 확률
    }
}

// 결과 출력 함수
void displayAccidentProbability(double Va, double Vb, double aa, double ab, double D, double reactionTime, double brakingDistance) {
    double safeDistance = calculateSafeDistance(Va, reactionTime, brakingDistance);
    double accidentProbability = calculateAccidentProbability(D, safeDistance);

    std::cout << "차 A 속도: " << Va << " km/h\n";
    std::cout << "차 B 속도: " << Vb << " km/h\n";
    std::cout << "차량 간 거리: " << D << " m\n";
    std::cout << "안전 거리: " << safeDistance << " m\n";
    std::cout << "사고 확률: " << std::fixed << std::setprecision(2) << accidentProbability * 100 << "%\n";
}

int main() {
    // 초기 매개변수 설정
    double Va = 60.0; // 차 A 속도 (km/h)
    double Vb = 80.0;  // 차 B 속도 (km/h)
    double aa = -2.0;   // 차 A 가속도 (m/s^2)
    double ab = -1.5;   // 차 B 가속도 (m/s^2)
    double D = 50.0;   // 차량 간 거리 (m)
    double reactionTime = 0.5; // 반응 시간 (s)
    double brakingDistance = 10.0; // 제동 거리 (m)

    // 사고 확률 분석 실행
    displayAccidentProbability(Va, Vb, aa, ab, D, reactionTime, brakingDistance);

    return 0;
}