#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

// 절대적 안전 거리 계산 함수
double calculateSafeDistance(double Vp1, double tr, double to, double tn, double ah1) {
    return Vp1 * (tr + to + tn / 2.0) + (Vp1 * Vp1) / (2.0 * ah1);
}

// 결과 출력 함수
void displaySafeDistanceAnalysis(double speed, std::vector<double> brt_values, double to, double tn, double ah1) {
    std::cout << "Speed: " << speed << " km/h\n";
    std::cout << "BRT(s)\tSafe Distance(m)\n";
    for (double tr : brt_values) {
        double Vp1 = speed * 1000.0 / 3600.0; // 속도를 km/h에서 m/s로 변환
        double safeDistance = calculateSafeDistance(Vp1, tr, to, tn, ah1);
        std::cout << std::fixed << std::setprecision(2) << tr << "\t" << safeDistance << "\n";
    }
}

int main() {
    // 초기 매개변수 설정
    double to = 0.5;       // 제동 활성화 지연 시간 (s)
    double tn = 0.2;       // 압력 증가 시간 (s)
    double ah1 = 9.0;      // 후속 차량 감속도 (m/s^2)
    std::vector<double> brt_values = {0.74, 0.85, 1.10, 1.41, 1.73, 1.99}; // BRT 분위수

    // 속도 범위 설정
    std::vector<double> speeds = {100.0}; // 테스트용 속도 (km/h)

    // 분석 실행
    for (double speed : speeds) {
        displaySafeDistanceAnalysis(speed, brt_values, to, tn, ah1);
    }

    return 0;
}
