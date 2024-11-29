#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>

// 제동 거리 계산 함수 (후속 차량)
double calculateBrakingDistanceA(double VA, double TrA, double g, double f) {
    return VA * TrA + (VA * VA) / (2 * g * f);
}

// 제동 거리 계산 함수 (선행 차량)
double calculateBrakingDistanceB(double VB, double g, double f) {
    return (VB * VB) / (2 * g * f);
}

// 안전 차간 거리 계산 함수
double calculateSafeGap(double SB, double SA, double D) {
    return SB - SA + D;
}

// 표준 정규 분포 기반 CDF 계산
double gaussianCDF(double z) {
    return 0.5 * (1.0 + erf(z / sqrt(2.0)));
}

// 충돌 확률 계산 함수
double calculateCollisionProbability(double delta_mean, double delta_stddev) {
    double z = (0 - delta_mean) / delta_stddev; // Z-값 계산 (δ < 0 기준)
    return 1.0 - gaussianCDF(z); // 충돌 확률
}

int main() {
    // 매개변수 초기화
    double VA, VB, TrA, D, f, g = 9.8;

    // 사용자 입력
    std::cout << "Enter following vehicle speed (VA in m/s): ";
    std::cin >> VA;

    std::cout << "Enter leading vehicle speed (VB in m/s): ";
    std::cin >> VB;

    std::cout << "Enter reaction time of following vehicle (TrA in seconds): ";
    std::cin >> TrA;

    std::cout << "Enter initial distance between vehicles (D in meters): ";
    std::cin >> D;

    std::cout << "Enter road friction coefficient (f): ";
    std::cin >> f;

    // 제동 거리 계산
    double SA = calculateBrakingDistanceA(VA, TrA, g, f);
    double SB = calculateBrakingDistanceB(VB, g, f);

    // 안전 차간 거리 계산
    double delta_mean = calculateSafeGap(SB, SA, D);

    // 표준편차 설정 (±10%의 오차를 가정)
    double delta_stddev = 0.1 * fabs(delta_mean);

    // 충돌 확률 계산
    double collision_probability = calculateCollisionProbability(delta_mean, delta_stddev);

    // 결과 출력
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nResults:\n";
    std::cout << "Braking Distance of A (SA): " << SA << " m\n";
    std::cout << "Braking Distance of B (SB): " << SB << " m\n";
    std::cout << "Safe Gap (δ): " << delta_mean << " m\n";
    std::cout << "Collision Probability: " << collision_probability * 100.0 << " %\n";

    return 0;
}
