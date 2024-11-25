#include <iostream>
#include <iomanip> // 출력 포맷 설정
#include <cmath>   // 수학 계산 함수 사용

using namespace std;

// 초기거리(50m)가 유지될 경우 충돌이 발생하지 않으며, 시간이 지남에 따라 차량 간 거리가 줄어듦
// 선행 차량의 감속도가 더 크거나 후속 차량의 반응이 늦을 경우, 충돌 가능성이 증가

// 차량 상태를 나타내는 구조체
struct Vehicle {
    double position;     // 위치 (m)
    double speed;        // 속도 (km/h)
    double deceleration; // 감속도 (m/s^2)
};

// 차량의 위치 계산 함수
double calculatePosition(double initialPosition, double initialSpeed, double time, double deceleration) {
    // 속도는 km/h 단위를 m/s로 변환
    double speedInMetersPerSecond = initialSpeed * 1000.0 / 3600.0;
    return initialPosition + speedInMetersPerSecond * time - 0.5 * deceleration * time * time;
}

// 메인 함수
int main() {
    // 초기 설정
    double initialDistance = 50.0; // 초기 차량 간 거리 (m)

    // 차량 초기 상태
    Vehicle vehicle1 = {-initialDistance, 100.0, 0.0}; // 후속 차량
    Vehicle vehicle2 = {0.0, 100.0, 9.0};             // 선행 차량

    // 시뮬레이션 설정
    double totalTime = 5.0;     // 총 시뮬레이션 시간 (s)
    double timeStep = 0.1;      // 시간 간격 (s)
    double currentTime = 0.0;   // 현재 시간 (s)

    // 출력 헤더
    cout <<   fixed <<   setprecision(2); // 소수점 2자리로 고정
    cout << "Time(s)\tVehicle1_Pos(m)\tVehicle2_Pos(m)\tDelta_S(m)\n";

    // 시뮬레이션 루프
    while (currentTime <= totalTime) {
        // 차량 위치 업데이트
        double vehicle1Position = calculatePosition(vehicle1.position, vehicle1.speed, currentTime, vehicle1.deceleration);
        double vehicle2Position = calculatePosition(vehicle2.position, vehicle2.speed, currentTime, vehicle2.deceleration);

        // 차량 간 거리 계산
        double deltaS = vehicle2Position - vehicle1Position;

        // 결과 출력
        cout << currentTime << "\t" << vehicle1Position << "\t\t" << vehicle2Position << "\t\t" << deltaS << "\n";

        // 충돌 조건 확인
        if (deltaS <= 0.0) {
            cout << "Collision occurred at time: " << currentTime << " seconds\n";
            break;
        }

        // 시간 증가
        currentTime += timeStep;
    }

    return 0;
}
