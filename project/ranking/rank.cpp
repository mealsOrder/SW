#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// 함수: 제1 가중치 계산
double calculateFirstWeight(double freq1, double freq2) {
    return freq1 * freq2;
}

// 함수: 제2 가중치 계산
double calculateSecondWeight(std::vector<double> firstWeights, double dampingFactor = 0.85) {
    double rank = 0.0;
    for (double weight : firstWeights) {
        rank += weight;
    }
    return dampingFactor * rank;
}

int main() {
    // 예시 데이터
    double freq1 = 3;  // 제1 데이터의 특징단어 빈도
    double freq2 = 5;  // 제3 데이터의 특징단어 빈도

    // 제1 가중치 계산
    double firstWeight = calculateFirstWeight(freq1, freq2);
    std::cout << "제1 가중치: " << firstWeight << std::endl;

    // 제2 가중치 계산을 위한 벡터 준비
    std::vector<double> firstWeights = {firstWeight, 4.0, 6.0};  // 임의의 다른 가중치 포함
    double secondWeight = calculateSecondWeight(firstWeights);
    std::cout << "제2 가중치: " << secondWeight << std::endl;

    return 0;
}