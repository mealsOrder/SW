#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip> // 출력 포맷 설정
#include<cmath>

using namespace std;

struct Vehicle{
    double speed;           // 속도 (km/h)
    double position;        // 위치 (m)
    double acceleration;    // 가속도 (m/s^2)
};

/**
 * @brief 차량의 위치 계산 함수
 * 
 * S = initialPosition + initialSpeed * time - 1/2 * a * time * time
 * 
 * @param initialPosition 초기 위치
 * @param initialSpeed 초기 속도
 * @param time 경과 시간
 * @param acceleration 가속도 또는 감속도
 * @return double S
 */
double calculatePosition(double initialPosition, double initialSpeed, double time, double acceleration) {
    // 속도는 km/h 단위에서 m/s로 변환 필요
    double speedInMetersPerSecond = initialSpeed * 1000.0 / 3600.0;
    return initialPosition + speedInMetersPerSecond * time - 0.5 * acceleration * time * time;
}

// 수식 정리 및 변수 해석

/**
 * @brief Absolutely Safe Distance : 절대적 안전 거리 ... (1)
 * 
 * S(abs) = S(E) + V(p1)*( t(r)+t(o)+t(n)/2 ) + V^2(pl) / 2*a(h1)
 * 
 * @param SE 차량이 정지한 상태에서의 최소 거리
 * @param Vp1 후속 차량의 초기 속도
 * @param tr 운전자 반응 시간
 * @param to 브레이크 시스템 활성화 지연 시간
 * @param tn 압력 증가 시간
 * @param ah1 후속 차량의 감속도
 * @return double S(abs) : Absolutely Safe Distance
 */
double calculateAbsoluteSafeDistance(double SE, double Vp1, double tr, double to, double tn, double ah1) {
    double TR = tr + to + tn / 2.0;
    return SE + Vp1 * TR + (Vp1 * Vp1) / (2.0 * ah1);
}


/**
 * @brief Non-braking Time : 비제동 시간 T(R) ... (2)
 * 
 * T(R) = t(r)+t(o)+t(n)/2
 * 
 * @param tr 운전자 반응 시간
 * @param to 브레이크 시스템 활성화 지연 시간
 * @param tn 압력 증가 시간
 * @return double T(R) : Non-braking Time
 */
double calculateNonBrakingTime(double tr, double to, double tn) {
    return tr + to + tn / 2.0;
}


/**
 * @brief Expanded Absolutely Safe Distance : 절대적 안전 거리 재정의 ... (3)
 * 
 * S(abs) = S(E) + S(tr) + S(to) + S(n) + S(h)
 * 
 * @param SE 차량이 정지한 상태에서의 최소 거리
 * @param Str 반응 거리 [ V(p1)*t(r) ]
 * @param Sto 브레이크 활성화 지연 거리 [ V(p1)*t(o) ]
 * @param Sn 압력 증가 거리 [ V(p1) * t(n) / 2 ]
 * @param Sh 제동 거리 [ V(p1)*V(p1) / 2*a(h1) ]
 * @return double Expanded Absolutely Safe Distance
 */
double calculateExpandedAbsoluteSafeDistance(double SE, double Str, double Sto, double Sn, double Sh) {
    return SE + Str + Sto + Sn + Sh;
}

/**
 * @brief Relatively Safe Distance : 상대적 안전 거리 ... (4)
 * 
 * S(rel) = S(E) + V(P)*( t(r)+t(o)+t(n)/2 ) + V(p)*V(p)/ 2*a(h1) - V(p)*V(p)/ 2*a(h2)
 * 
 * @param SE 차량이 정지한 상태에서의 최소 거리
 * @param Vp 두 차량의 초기 속도
 * @param tr 운전자 반응 시간
 * @param to 브레이크 시스템 활성화 지연 시간
 * @param tn 압력 증가 시간
 * @param ah1 후속 차량의 감속도
 * @param ah2 선행 차량의 감속도
 * @return double S(rel) : Relatively Safe Distance
 */
double calculateRelativeSafeDistance(double SE, double Vp, double tr, double to, double tn, double ah1, double ah2) {
    double TR = tr + to + tn / 2.0;
    double brakingDistance1 = (Vp * Vp) / (2.0 * ah1);
    double brakingDistance2 = (Vp * Vp) / (2.0 * ah2);
    return SE + Vp * TR + brakingDistance1 - brakingDistance2;
}

/**
 * @brief Same Condition Relatively Safe Distance : 동일 감속도 조건의 상대적 안전 거리 ... (5)
 * 
 * S(rel) = S(E) + V(p)*T(R), ah1 == ah2 
 * 
 * @param SE 차량이 정지한 상태에서의 최소 거리
 * @param Vp 두 차량의 초기 속도
 * @param TR 비제동 시간
 * @return double 
 */
double calculateSimplifiedRelativeSafeDistance(double SE, double Vp, double TR) {
    return SE + Vp * TR;
}


int main(){
    // 차량 초기 상태 설정
    Vehicle vehicle1 = {100.0, -50.0, 0.0}; // 후속 차량: 속도 100km/h, 초기 위치 -50m
    Vehicle vehicle2 = {100.0, 0.0, 0.0};  // 선행 차량: 속도 100km/h, 초기 위치 0m

    // 시간 단계별 데이터
    double timeIntervals[] = {0.5, 0.2, 0.2, 0.5, 0.2, 2.09, 0.9}; // 각 단계의 시간 구간
    double decelerations[] = {0.0, 0.0, 9.0, 9.0, 9.0, 9.0, 9.0}; // 각 단계에서 선행 차량의 감속도 (m/s^2)
    
    cout <<  fixed <<  setprecision(2); // 소수점 2자리 고정 출력
    cout << "Time(s)\tVehicle1_Pos(m)\tVehicle2_Pos(m)\tDelta_S(m)\n";

    double currentTime = 0.0;
    for (size_t i = 0; i < 7; ++i) {
        // 시간 증가
        currentTime += timeIntervals[i];

        // 차량 1(후속 차량)과 차량 2(선행 차량)의 위치 업데이트
        vehicle1.position = calculatePosition(vehicle1.position, vehicle1.speed, timeIntervals[i], 0.0);
        vehicle2.position = calculatePosition(vehicle2.position, vehicle2.speed, timeIntervals[i], decelerations[i]);

        // 차량 간 거리 계산
        double deltaS = vehicle2.position - vehicle1.position;

        // 결과 출력
        cout << " " << currentTime << "\t " << vehicle1.position << "\t\t" << vehicle2.position << "\t\t" << deltaS << "\n";

        // 속도 업데이트 (감속 적용)
        vehicle2.speed -= decelerations[i] * timeIntervals[i] * 3.6; // m/s를 km/h로 변환
    }

    return 0;
}