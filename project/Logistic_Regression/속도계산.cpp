#include <iostream>
#include <vector>
#include <cmath>

struct Frame {
    double x;
    double y;
};

double calculateDistance(const Frame& f1, const Frame& f2) {
    return std::sqrt(std::pow(f2.x - f1.x, 2) + std::pow(f2.y - f1.y, 2));
}

int main() {
    // 프레임 데이터 (예시)
    std::vector<Frame> frames = {
        {0.0, 0.0},  // 프레임 1
        {1.0, 0.0},  // 프레임 2
        {2.5, 0.0},  // 프레임 3
        {4.0, 0.0},  // 프레임 4
        {5.5, 0.0},  // 프레임 5
        {7.0, 0.0},  // 프레임 6
        {8.5, 0.0},  // 프레임 7
        {10.0, 0.0}, // 프레임 8
        {11.5, 0.0}, // 프레임 9
        {13.0, 0.0}  // 프레임 10
    };

    double deltaTime = 1.0 / 30.0; // 30 FPS 기준
    std::vector<double> speeds;

    // 속도 계산
    for (size_t i = 1; i < frames.size(); ++i) {
        double distance = calculateDistance(frames[i - 1], frames[i]);
        double speed = distance / deltaTime;
        speeds.push_back(speed);
    }

    // 가속도 계산
    std::vector<double> accelerations;
    for (size_t i = 1; i < speeds.size(); ++i) {
        double acceleration = (speeds[i] - speeds[i - 1]) / deltaTime;
        accelerations.push_back(acceleration);
    }

    // 결과 출력
    std::cout << "속도 (m/s):\n";
    for (const auto& speed : speeds) {
        std::cout << speed << "\n";
    }

    std::cout << "\n가속도 (m/s^2):\n";
    for (const auto& acceleration : accelerations) {
        std::cout << acceleration << "\n";
    }

    return 0;
}