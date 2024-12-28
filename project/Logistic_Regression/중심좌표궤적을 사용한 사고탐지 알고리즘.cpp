#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

// 차량 정보를 저장하는 구조체
struct Vehicle {
    int id;
    double x, y; // 중심 좌표
    double width, height; // 경계 상자 크기
    double speed = 0.0; // 속도 (m/s)
    double acceleration = 0.0; // 가속도 (m/s²)
    vector<pair<double, double>> trajectory; // 궤적 정보
};

// 유틸리티 함수: 두 점 간 유클리드 거리 계산
double euclideanDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// 두 차량의 경계 상자 겹침 여부 확인
bool isBoundingBoxOverlapping(const Vehicle &a, const Vehicle &b) {
    return (2 * fabs(a.x - b.x) < a.width + b.width) &&
           (2 * fabs(a.y - b.y) < a.height + b.height);
}

// 궤적 벡터의 크기 계산
double vectorMagnitude(double x, double y) {
    return sqrt(x * x + y * y);
}

// 두 궤적 간 교차 각도 계산
double calculateIntersectionAngle(const Vehicle &a, const Vehicle &b) {
    if (a.trajectory.size() < 2 || b.trajectory.size() < 2) return 0.0;

    auto [ax1, ay1] = a.trajectory[a.trajectory.size() - 2];
    auto [ax2, ay2] = a.trajectory.back();
    auto [bx1, by1] = b.trajectory[b.trajectory.size() - 2];
    auto [bx2, by2] = b.trajectory.back();

    double ux = ax2 - ax1, uy = ay2 - ay1;
    double vx = bx2 - bx1, vy = by2 - by1;

    double dotProduct = ux * vx + uy * vy;
    double magnitudeU = vectorMagnitude(ux, uy);
    double magnitudeV = vectorMagnitude(vx, vy);

    return acos(dotProduct / (magnitudeU * magnitudeV)) * 180.0 / M_PI; // 각도를 도 단위로 반환
}

// 차량의 속도 계산 (m/s 단위로 반환)
double calculateSpeed(const Vehicle &v, double frameInterval) {
    if (v.trajectory.size() < 2) return 0.0;

    auto [x1, y1] = v.trajectory[v.trajectory.size() - 2];
    auto [x2, y2] = v.trajectory.back();

    return euclideanDistance(x1, y1, x2, y2) / frameInterval;
}

// 차량의 가속도 계산
double calculateAcceleration(double speed1, double speed2, double frameInterval) {
    return (speed2 - speed1) / frameInterval / 1000;
}

// 사고 탐지 함수
bool detectAccident(const Vehicle &a, const Vehicle &b, double angleThreshold, double accelThreshold) {
    double intersectionAngle = calculateIntersectionAngle(a, b);
    double accelerationChange = fabs(a.acceleration - b.acceleration);

    return (intersectionAngle > angleThreshold) && (accelerationChange > accelThreshold);
}

// 차량 데이터 출력 함수
void printVehicleStatus(const Vehicle &v) {
    // 속도를 km/h 단위로 변환
    double speed_kmh = v.speed * 1000 / 3600;
    cout << "차량 ID: " << v.id << ", 위치: (" << v.x << ", " << v.y
         << "), 속도: " << speed_kmh << " km/h, 가속도: " << v.acceleration << " m/s²" << endl;
}

int main() {
    // 프레임 간 시간 간격 (초)
    double frameInterval = 1.0 / 30.0; // 30 FPS 기준

    // 차량 목록 초기화
    unordered_map<int, Vehicle> vehicles = {
        {1, {1, 100, 100, 50, 30}}, // 차량 1: 초기 위치 (100, 100)
        {2, {2, 120, 110, 50, 30}}, // 차량 2: 초기 위치 (120, 110)
        {3, {3, 90, 90, 40, 25}}    // 차량 3: 초기 위치 (90, 90)
    };

    // 시뮬레이션: 차량의 이동 궤적 설정
    vehicles[1].trajectory = {{100, 100}, {105, 105}, {110, 110}};
    vehicles[2].trajectory = {{120, 110}, {115, 105}, {110, 100}};
    vehicles[3].trajectory = {{90, 90}, {93, 88}, {96, 86}};

    // 각 차량의 속도 및 가속도 계산
    for (auto &pair : vehicles) {
        Vehicle &v = pair.second;
        double prevSpeed = v.speed;
        v.speed = calculateSpeed(v, frameInterval);
        v.acceleration = calculateAcceleration(prevSpeed, v.speed, frameInterval);
        printVehicleStatus(v);
    }

    cout << "----------------------------------" << endl;

    // 시뮬레이션 케이스: 각 차량 간 사고 탐지
    vector<pair<int, int>> testPairs = {{1, 2}, {1, 3}, {2, 3}};
    for (const auto &[id1, id2] : testPairs) {
        Vehicle &v1 = vehicles[id1];
        Vehicle &v2 = vehicles[id2];

        cout << "테스트 케이스: 차량 " << id1 << "과 차량 " << id2 << endl;
        if (isBoundingBoxOverlapping(v1, v2)) {
            bool accident = detectAccident(v1, v2, 45.0, 2.0); // 임계값: 45도, 가속도 변화 2.0
            if (accident) {
                cout << "-> 사고 탐지됨!" << endl;
            } else {
                cout << "-> 사고 없음." << endl;
            }
        } else {
            cout << "-> 경계 상자 겹침 없음." << endl;
        }
    }

    return 0;
}
