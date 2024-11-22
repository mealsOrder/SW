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
double computeCost(const vector<vector<double>>& X, const vector<double>& y, const vector<double>& theta) {
    double cost = 0.0;
    int m = X.size(); // Number of training examples
    for (int i = 0; i < m; i++) {
        double h = hypothesis(theta, X[i]);
        cost += -y[i] * log(h) - (1 - y[i]) * log(1 - h);
    }
    return cost / m;
}

// Gradient Descent
void gradientDescent(vector<vector<double>>& X, vector<double>& y, vector<double>& theta, double alpha, int iterations) {
    int m = X.size(); // Number of training examples
    int n = theta.size(); // Number of features
    vector<double> gradient(n, 0.0);

    for (int iter = 0; iter < iterations; iter++) {
        // Compute gradient
        fill(gradient.begin(), gradient.end(), 0.0);
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

        // Optionally, print cost for debugging
        if (iter % 100 == 0) {
            double cost = computeCost(X, y, theta);
            cout << "Iteration " << iter << ", Cost: " << cost << endl;
        }
    }
}

// Main function
int main() {
    // Example dataset
    vector<vector<double>> X = {
        {1.0, 2.0}, // Feature 1, Feature 2
        {1.0, 3.0},
        {1.0, 4.0},
        {1.0, 5.0}
    };
    vector<double> y = {0, 0, 1, 1}; // Labels
    vector<double> theta = {0.0, 0.0}; // Initial parameters
    double alpha = 0.1; // Learning rate
    int iterations = 1000; // Number of iterations

    gradientDescent(X, y, theta, alpha, iterations);

    // Print final parameters
    cout << "Final parameters:" << endl;
    for (size_t i = 0; i < theta.size(); i++) {
        cout << "Theta[" << i << "]: " << theta[i] << endl;
    }

    return 0;
}
