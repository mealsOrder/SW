#include <iostream>
#include <iomanip>
#include <cmath>

// 차량 상태를 나타내는 구조체
struct Vehicle {
    double speed;        // 속도 (m/s)
    double distance;     // 차량 위치 (m)
    double deceleration; // 감속도 (m/s^2)
};

// 시뮬레이션 단계 계산
void simulateStep(Vehicle& vehicle1, Vehicle& vehicle2, double& time, double timeStep, double& relativeDistance) {
    // 선행 차량 감속
    if (vehicle2.speed > 0) {
        vehicle2.speed = std::max(0.0, vehicle2.speed - vehicle2.deceleration * timeStep);
        vehicle2.distance += vehicle2.speed * timeStep; // 선행 차량 이동 거리
    }

    // 후속 차량 감속
    if (vehicle1.speed > 0) {
        vehicle1.speed = std::max(0.0, vehicle1.speed - vehicle1.deceleration * timeStep);
        vehicle1.distance += vehicle1.speed * timeStep; // 후속 차량 이동 거리
    }

    // 두 차량 간 상대 거리 계산
    relativeDistance = vehicle2.distance - vehicle1.distance;

    // 시간 업데이트
    time += timeStep;
}

int main() {
    // 초기 설정: Table 1 데이터
    Vehicle vehicle1 = {27.78, -50.0, 0.0}; // 후속 차량: 초기 속도 27.78m/s, 초기 거리 -50m
    Vehicle vehicle2 = {27.78, 0.0, 9.0};   // 선행 차량: 초기 속도 27.78m/s, 감속도 9m/s^2
    double reactionTime = 0.9;              // 후속 차량 반응 시간 (초)
    double brakeDelay = 0.5;                // 브레이크 지연 시간 (초)
    double simulationTime = 0.0;            // 시뮬레이션 경과 시간
    double timeStep = 0.1;                  // 시간 단계 (0.1초)
    double relativeDistance = vehicle2.distance - vehicle1.distance; // 초기 차량 간 거리

    // 후속 차량 감속도 설정
    double brakingDeceleration = 9.0;

    // 시뮬레이션 루프
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Time(s)\tVehicle1_Speed(m/s)\tVehicle2_Speed(m/s)\tRelative_Distance(m)\n";

    while (simulationTime <= 5.0) { // 5초 동안 시뮬레이션
        if (simulationTime >= reactionTime) {
            vehicle1.deceleration = brakingDeceleration; // 반응 시간 이후 후속 차량 감속 시작
        }

        simulateStep(vehicle1, vehicle2, simulationTime, timeStep, relativeDistance);

        // 출력
        std::cout << simulationTime << "\t"
                  << vehicle1.speed << "\t\t"
                  << vehicle2.speed << "\t\t"
                  << relativeDistance << "\n";

        // 충돌 여부 확인
        if (relativeDistance <= 0.0) {
            std::cout << "Collision occurred at time: " << simulationTime << " seconds\n";
            break;
        }
    }

    if (relativeDistance > 0.0) {
        std::cout << "No collision occurred within the simulation time.\n";
    }

    return 0;
}
