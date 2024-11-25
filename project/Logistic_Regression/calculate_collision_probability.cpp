#include <iostream>
#include <iomanip>
#include <cmath>

// 가우시안 분포 함수 (표준 정규분포 CDF 계산)
double gaussianCDF(double x) {
    return 0.5 * (1.0 + erf(x / sqrt(2.0)));
}

// 제동 거리 계산 함수
double calculateBrakingDistance(double Vp1, double tr, double to, double tn, double ah1) {
    return Vp1 * (tr + to + tn / 2.0) + (Vp1 * Vp1) / (2.0 * ah1);
}

// 충돌 확률 계산 함수
double calculateCollisionProbability(double S_initial, double mean_brake_distance, double std_dev) {
    double z = (S_initial - mean_brake_distance) / std_dev; // Z-값 계산
    return 1.0 - gaussianCDF(z); // 충돌 확률
}

int main() {
    // 초기 매개변수 설정
    double S_initial; // 초기 차간 거리 (m)
    std::cout << "Enter initial distance between vehicles (S_initial in meters): ";
    std::cin >> S_initial;

    double speed_kmh; // 초기 속도 (km/h)
    std::cout << "Enter initial speed of the following vehicle (in km/h): ";
    std::cin >> speed_kmh;

    double tr = 1.10; // 평균 BRT (s)
    double to = 0.5;  // 제동 활성화 지연 시간 (s)
    double tn = 0.2;  // 압력 증가 시간 (s)
    double ah1 = 9.0; // 후속 차량 감속도 (m/s^2)

    // 속도를 m/s로 변환
    double Vp1 = speed_kmh * 1000.0 / 3600.0;

    // 평균 제동 거리 계산
    double mean_brake_distance = calculateBrakingDistance(Vp1, tr, to, tn, ah1);

    // 표준 편차를 설정 (예: ±10% 오차를 가정)
    double std_dev = 0.1 * mean_brake_distance;

    // 충돌 확률 계산
    double collision_probability = calculateCollisionProbability(S_initial, mean_brake_distance, std_dev);

    // 결과 출력
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nResults:\n";
    std::cout << "Mean Braking Distance: " << mean_brake_distance << " m\n";
    std::cout << "Collision Probability: " << collision_probability * 100.0 << " %\n";

    return 0;
}
