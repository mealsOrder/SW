#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

// 정규 분포에서 Z-값에 따라 분위수 계산
double calculateQuantile(double mean, double sd, double z) {
    return mean + z * sd;
}

// 분위수 데이터 출력
void printQuantileResults(double mean, double sd, const  vector< pair<double, double>>& quantiles) {
    cout << "Quantile\tZ-Value\tCalculated BRT (s)\n";
    for (const auto& q : quantiles) {
        double quantileValue = calculateQuantile(mean, sd, q.second);
        cout << q.first << "\t\t" << q.second << "\t" <<  fixed <<  setprecision(2) << quantileValue << "\n";
    }
}

int main() {
    // 통계 매개변수
    double meanBRT = 1.16; // 평균값
    double sdBRT = 0.42;   // 표준편차

    // 분위수에 따른 Z-값 정의 (p값: 분위수)
    vector< pair<double, double>> quantiles = {
        {0.10, -1.28}, // 10% 분위수
        {0.25, -0.67}, // 25% 분위수
        {0.50, 0.0},   // 중위값 (Z = 0)
        {0.75, 0.67},  // 75% 분위수
        {0.90, 1.28},  // 90% 분위수
        {0.99, 2.33}   // 99% 분위수
    };

    // 출력
    cout << "BRT Statistical Analysis\n";
    cout << "Mean BRT: " << meanBRT << " s, SD: " << sdBRT << " s\n";
    cout << "-----------------------------------\n";
    printQuantileResults(meanBRT, sdBRT, quantiles);

    // 최소값 및 최대값 테스트
    double minBRT = 0.5;  // 최소값
    double maxBRT = 2.7;  // 최대값
    cout << "\nMinimum BRT: " << minBRT << " s\n";
    cout << "Maximum BRT: " << maxBRT << " s\n";

    return 0;
}
