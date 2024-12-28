#include <iostream>
#include <vector>
#include <algorithm>

double calculatePercentile(const std::vector<double>& values, double input) {
    // 벡터를 복사하고 정렬
    std::vector<double> sortedValues = values;
    std::sort(sortedValues.begin(), sortedValues.end());
    
    // input 값이 몇 번째 위치에 있는지 찾음
    auto it = std::lower_bound(sortedValues.begin(), sortedValues.end(), input);
    int rank = std::distance(sortedValues.begin(), it);
    
    // 퍼센트로 변환
    double percentile = (static_cast<double>(rank) / sortedValues.size()) * 100.0;
    return percentile;
}

int main() {
    // 최소값을 저장한 벡터
    std::vector<double> Values = {0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.09,0.11};
    
    // 새로 들어온 값
    double newValue;
    std::cout << "새로 들어온 값을 입력하세요: ";
    std::cin >> newValue;
    
    // 백분위 계산
    double percentile = calculatePercentile(Values, newValue);
    std::cout << "입력값 " << newValue << "는 값 분포의 " << percentile/100 << "번째 백분위에 위치합니다." << std::endl;

    return 0;
}
