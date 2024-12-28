#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 배경 강도 함수 λ(t)
double lambda(double t) {
    return 0.8 * (sin(t) + 1); // 예시로 사인 함수 사용
}

// 자기-자극성 강도 μ(t)
double mu(double t) {
    return 0.04; // 상수 값 예시
}

// M(t): μ(t)의 적분
double M(double t, double dt = 0.01) {
    double integral = 0.0;
    for (double s = 0; s < t; s += dt) {
        integral += mu(s) * dt;
    }
    return integral;
}

// 평균 사고 수 m(t) 계산
double m(double t, double dt = 0.01) {
    double result = 0.0;
    double Mt = M(t, dt);
    for (double s = 0; s < t; s += dt) {
        result += exp(-M(s, dt)) * lambda(s) * dt;
    }
    return exp(Mt) * result;
}

// 분포 함수 f(n, t) 계산
vector<vector<double>> compute_f(int max_n, double max_t, double dt) {
    int time_steps = static_cast<int>(max_t / dt);
    vector<vector<double>> f(max_n + 1, vector<double>(time_steps + 1, 0.0));
    
    // 초기 조건 f(0, 0) = 1
    f[0][0] = 1.0;
    
    for (int j = 0; j < time_steps; ++j) {
        double t = j * dt;
        for (int n = 0; n <= max_n; ++n) {
            double lambda_t = lambda(t);
            double mu_t = mu(t);
            double prev_f = (n > 0) ? f[n - 1][j] : 0.0;
            f[n][j + 1] = f[n][j] + dt * ((lambda_t + mu_t * (n - 1)) * prev_f 
                                         - (lambda_t + mu_t * n) * f[n][j]);
        }
    }
    return f;
}

// 사고 간 시간 분포 h_k(τ) 계산
double h_k(int k, double tau, double dt = 0.01) {
    double result = 0.0;
    for (double s = 0.0; s < tau; s += dt) {
        double lambda_s = lambda(s);
        double mu_s = mu(s);
        double lambda_tau = lambda(s + tau);
        double mu_tau = mu(s + tau);
        double exp_factor = exp(-(M(s + tau, dt) - M(s, dt)) - (k - 1) * (M(s + tau, dt) - M(s, dt)));
        result += (lambda_s + mu_s * (k - 2)) * (lambda_tau + mu_tau * (k - 1)) * exp_factor * dt;
    }
    return result;
}

int main() {
    // 시간 설정
    double t = 10.0;
    double dt = 0.01;

    // 평균 사고 수 계산
    cout << "평균 사고 수 m(" << t << ") = " << m(t, dt) << endl;

    // 분포 함수 계산
    int max_n = 30; // 최대 사고 수
    double max_t = 10.0; // 최대 시간
    auto f = compute_f(max_n, max_t, dt);
    cout << "f(5, 10) = " << f[5][static_cast<int>(max_t / dt)] << endl;

    // 사고 간 시간 분포 계산
    int k = 3; // k번째 사고
    double tau = 5.0; // 사고 간 시간
    cout << "h_" << k << "(" << tau << ") = " << h_k(k, tau, dt) << endl;

    return 0;
}