#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the mean of a vector
double mean(vector<double> v) {
    double sum = 0.0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum / v.size();
}

// Function to calculate the slope and intercept of a linear regression line
void linearRegression(vector<double> x, vector<double> y, double &slope, double &intercept) {
    double x_mean = mean(x);
    double y_mean = mean(y);
    double numerator = 0.0;
    double denominator = 0.0;
    for (int i = 0; i < x.size(); i++) {
        numerator += (x[i] - x_mean) * (y[i] - y_mean);
        denominator += pow(x[i] - x_mean, 2);
    }
    slope = numerator / denominator;
    intercept = y_mean - slope * x_mean;
}

int main() {
    vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector<double> y = {2.0, 4.0, 5.0, 4.0, 5.0};
    double slope, intercept;
    linearRegression(x, y, slope, intercept);
    cout << "Slope: " << slope << endl;
    cout << "Intercept: " << intercept << endl;
    return 0;
}