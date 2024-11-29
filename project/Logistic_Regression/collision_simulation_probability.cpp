#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib> // 난수 생성을 위한 라이브러리

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

// 단일 시뮬레이션 함수
bool simulateCollision(double initialDistance, double vehicle1Speed, double vehicle2Speed, 
                       double reactionTime, double brakingDeceleration, double totalTime, double timeStep) {
    // 차량 초기 상태
    Vehicle vehicle1 = {-initialDistance, vehicle1Speed, 0.0}; // 후속 차량
    Vehicle vehicle2 = {0.0, vehicle2Speed, 9.0};              // 선행 차량 (감속도 9 m/s^2)

    double currentTime = 0.0;

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

        // 충돌 조건 확인
        if (deltaS <= 0.0) {
            return true; // 충돌 발생
        }

        // 시간 증가
        currentTime += timeStep;
    }

    return false; // 충돌 발생하지 않음
}

int main() {
    // 사용자 입력
    double initialDistance, vehicle1Speed, vehicle2Speed, reactionTime, brakingDeceleration;
    int numSimulations = 1000; // 시뮬레이션 반복 횟수

    cout << "Enter initial distance between vehicles (m): ";
    cin >> initialDistance;
    cout << "Enter speed of following vehicle (m/s): ";
    cin >> vehicle1Speed;
    cout << "Enter speed of leading vehicle (m/s): ";
    cin >> vehicle2Speed;
    cout << "Enter reaction time of following vehicle (s): ";
    cin >> reactionTime;
    cout << "Enter deceleration of following vehicle (m/s^2): ";
    cin >> brakingDeceleration;

    // 시뮬레이션 설정
    double totalTime = 5.0;   // 총 시뮬레이션 시간 (s)
    double timeStep = 0.1;    // 시간 간격 (s)

    // 충돌 횟수 기록
    int collisionCount = 0;

    // 시뮬레이션 반복
    for (int i = 0; i < numSimulations; ++i) {
        // 난수를 사용해 약간의 변동을 추가
        double randomReactionTime = reactionTime + (rand() % 100 - 50) / 100.0; // ±0.5초 변동
        double randomBrakingDeceleration = brakingDeceleration + (rand() % 100 - 50) / 100.0; // ±0.5m/s^2 변동

        if (simulateCollision(initialDistance, vehicle1Speed, vehicle2Speed, randomReactionTime, 
                              randomBrakingDeceleration, totalTime, timeStep)) {
            collisionCount++;
        }
    }

    // 충돌 확률 계산
    double collisionProbability = static_cast<double>(collisionCount) / numSimulations * 100.0;

    // 결과 출력
    cout << fixed << setprecision(2);
    cout << "\nSimulation Results:\n";
    cout << "Number of Simulations: " << numSimulations << "\n";
    cout << "Collision Count: " << collisionCount << "\n";
    cout << "Collision Probability: " << collisionProbability << "%\n";

    return 0;
}
