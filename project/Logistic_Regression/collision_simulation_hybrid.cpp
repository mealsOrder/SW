#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// 차량 상태를 나타내는 구조체
struct Vehicle {
    double position;     // 위치 (m)
    double speed;        // 속도 (m/s)
    double deceleration; // 감속도 (m/s^2)
};

// 차량 속도 및 위치 업데이트 함수
void updateVehicle(Vehicle& vehicle, double timeStep) {
    if (vehicle.speed > 0) {
        // 속도 감소
        vehicle.speed = max(0.0, vehicle.speed - vehicle.deceleration * timeStep);
        // 위치 업데이트
        vehicle.position += vehicle.speed * timeStep;
    }
}

// 메인 함수
int main() {
    // 초기 설정: 초기 차량 간 거리 줄이기 (20m)
    double initialDistance = 20.0; // 초기 차량 간 거리 (m)

    // 차량 초기 상태: 후속 차량의 감속도를 낮게 설정
    Vehicle vehicle1 = {-initialDistance, 100.0 / 3.6, 0.0}; // 후속 차량 (100 km/h -> m/s)
    Vehicle vehicle2 = {0.0, 100.0 / 3.6, 9.0};              // 선행 차량 (100 km/h -> m/s, 감속도 9 m/s^2)

    // 시뮬레이션 설정
    double totalTime = 5.0;     // 총 시뮬레이션 시간 (s)
    double timeStep = 0.1;      // 시간 간격 (s)
    double currentTime = 0.0;   // 현재 시간 (s)

    // 후속 차량 반응 시간 및 감속도
    double reactionTime = 1.2;       // 반응 시간 증가 (초)
    double brakingDeceleration = 6.0; // 후속 차량 감속도 감소 (m/s^2)

    // 출력 헤더
    cout << fixed << setprecision(2); // 소수점 2자리로 고정
    cout << "Time(s)\tVehicle1_Pos(m)\tVehicle1_Speed(m/s)\tVehicle2_Pos(m)\tVehicle2_Speed(m/s)\tDelta_S(m)\n";

    // 시뮬레이션 루프
    while (currentTime <= totalTime) {
        // 후속 차량 반응 시간 이후 감속 시작
        if (currentTime >= reactionTime) {
            vehicle1.deceleration = brakingDeceleration;
        }

        // 차량 상태 업데이트
        updateVehicle(vehicle1, timeStep);
        updateVehicle(vehicle2, timeStep);

        // 차량 간 거리 계산
        double deltaS = vehicle2.position - vehicle1.position;

        // 결과 출력
        cout << currentTime << "\t" << vehicle1.position << "\t\t" << vehicle1.speed
             << "\t\t\t" << vehicle2.position << "\t\t" << vehicle2.speed << "\t\t\t" << deltaS << "\n";

        // 충돌 조건 확인
        if (deltaS <= 0.0) {
            cout << "Collision occurred at time: " << currentTime << " seconds\n";
            break;
        }

        // 시간 증가
        currentTime += timeStep;
    }

    // 충돌이 발생하지 않은 경우
    if (currentTime > totalTime && vehicle2.position - vehicle1.position > 0.0) {
        cout << "No collision occurred within the simulation time.\n";
    }

    return 0;
}
