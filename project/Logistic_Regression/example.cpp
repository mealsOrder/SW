#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Sigmoid function
double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

// Hypothesis function
double hypothesis(const vector<double>& theta, const vector<double>& x) {
    double z = 0.0;
    for (size_t i = 0; i < theta.size(); i++) {
        z += theta[i] * x[i];
    }
    return sigmoid(z);
}

// Cost function
double computeCost(const vector<vector<double>>& X, const vector<int>& y, const vector<double>& theta) {
    double cost = 0.0;
    int m = X.size();
    for (int i = 0; i < m; i++) {
        double h = hypothesis(theta, X[i]);
        cost += -y[i] * log(h) - (1 - y[i]) * log(1 - h);
    }
    return cost / m;
}

// Gradient Descent
void gradientDescent(vector<vector<double>>& X, vector<int>& y, vector<double>& theta, double alpha, int iterations) {
    int m = X.size();
    int n = theta.size();
    vector<double> gradient(n, 0.0);

    for (int iter = 0; iter < iterations; iter++) {
        fill(gradient.begin(), gradient.end(), 0.0);

        // Compute gradient
        for (int i = 0; i < m; i++) {
            double h = hypothesis(theta, X[i]);
            for (int j = 0; j < n; j++) {
                gradient[j] += (h - y[i]) * X[i][j];
            }
        }

        // Update theta
        for (int j = 0; j < n; j++) {
            theta[j] -= (alpha / m) * gradient[j];
        }

        // Print cost for debugging
        if (iter % 100 == 0) {
            double cost = computeCost(X, y, theta);
            cout << "Iteration " << iter << ", Cost: " << cost << endl;
        }
    }
}

// Main function
int main() {
    // 데이터: [Bias term, 속도, 거리]
    vector<vector<double>> X = {
        {1.0, 60.0, 15.0}, // Bias term, 속도, 거리
        {1.0, 50.0, 20.0},
        {1.0, 80.0, 10.0},
        {1.0, 40.0, 25.0}
    };
    vector<int> y = {1, 0, 1, 0}; // 사고 여부: 1 (사고), 0 (미발생)

    vector<double> theta = {0.0, 0.0, 0.0}; // 초기 파라미터
    double alpha = 0.01; // 학습률
    int iterations = 1000; // 반복 횟수

    gradientDescent(X, y, theta, alpha, iterations);

    // 결과 출력
    cout << "Final parameters:" << endl;
    for (size_t i = 0; i < theta.size(); i++) {
        cout << "Theta[" << i << "]: " << theta[i] << endl;
    }

    // 특정 입력값으로 사고 확률 예측
    vector<double> test_input = {1.0, 60.0, 20.0}; // Bias term, 속도, 거리.

    double probability = hypothesis(theta, test_input);
    cout << "Predicted probability of accident: " << probability << endl;

    return 0;
}