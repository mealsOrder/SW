#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<random>
using namespace std;
const int MX = 100;
vector<int>v;

// wx + bias;
double linear_func(double x_data,double weights, double bias){
    return x_data*weights*bias;
}

// random linear - 
vector<double> loss_func(double weights,double bias,vector<int>x_data,vector<int>y_data){
    vector<double>grad(x_data.size(),0);
    for(int i=0;i<x_data.size();i++){
        grad[i] = 1/(i+1)*pow( (linear_func(x_data[i],weights,bias) - y_data[i]),2);
    }

    return grad;
}

// 미분의 중앙차분으로 구현 함, (전진차분, 후진 차분 도 있음)
double gradient_update(vector<int>x_data, vector<int>y_data, double weights, double bias, string grad_name){
    double h = log(10)-4;
    if(grad_name == "weights"){
        vector<double> forward = loss_func(weights + h, bias, x_data,y_data);
        vector<double> backward = loss_func(weights - h, bias, x_data,y_data);
        double forward_sum = 0;
        double backward_sum = 0;

        for(int i=0;i<forward.size();i++){
            forward_sum += forward[i];
            backward_sum += backward[i];
        }
        return (forward_sum - backward_sum)/(2*h);
    }else{
        vector<double> forward = loss_func(weights , bias + h, x_data,y_data);
        vector<double> backward = loss_func(weights , bias - h, x_data,y_data);
        double forward_sum = 0;
        double backward_sum = 0;

        for(int i=0;i<forward.size();i++){
            forward_sum += forward[i];
            backward_sum += backward[i];
        }
        return (forward_sum - backward_sum)/(2*h);
    }
}

vector<double> update(double learning_rate, double grad_w,double grad_b, double weights,double bias){
    vector<double> update_wb(2);
    weights = weights - learning_rate*grad_w;
    bias = bias - learning_rate*grad_b;

    update_wb[0] = weights;
    update_wb[1] = bias;

    return update_wb;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // y = x + 1, w = 1, b = 1
    // 2000 번 
    vector<int>x_data = {1,2,3,4,5};
    vector<int>y_data = {2,3,4,5,6};

    
    double weights = ((double)rand()/ RAND_MAX);
    double bias = ((double)rand()/ RAND_MAX);

    cout << "weight: " << weights << '\n';
    cout << "bias: " << bias << '\n';

    for(int i=0;i<MX;i++){
        cout << "weight : " << "[" << weights << "]  " << "bias : [" << bias << "]\n";
        double grad_w = gradient_update(x_data,y_data,weights,bias,"weights");
        double grad_b = gradient_update(x_data,y_data,weights,bias,"bias");
        vector<double> update_data = update(0.001,grad_w,grad_b,weights,bias);
        weights=update_data[0];
        bias=update_data[1];
    }

    cout << "Updated Weights : " << weights << '\n';
    cout << "Updated bias : " << bias << '\n';
    
    return 0;
}