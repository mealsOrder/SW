#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<random>
using namespace std;
const int MX = 2000;
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

    // random_device rd; 
    // mt19937 mt(rd()); 
    // uniform_int_distribution<int> dist(0, 99); 
    // auto randNum = dist(mt);


    // y = x + 1, w = 1, b = 1
    // 2000 번 
    vector<int>x_data = {1,2,3,4,5} ;
    vector<int>y_data = {2,3,4,5,6};

    
    double weights = ((double)rand()/ RAND_MAX);
    double bias = ((double)rand()/ RAND_MAX);

    cout << "weight: " << weights << '\n';
    cout << "bias: " << bias << '\n';

    // epoch 횟수 : 원하는 선형을 찾는 횟수
    // 원하는 이미지 혹은 원하는 vector 혹은 linear를 찾아가는 과정
    // 선형 : weight, bias 2개 (파라미터 두개), gpt-3 몇개일까요? ( 1300 억개 )
    // yolo_tiny, tiny ( 500 개) 원하는 값이 나오지가 않음. 알고리즘의 기본적인 원리를 알면
    // 이 모델을 튜닝하거나 혹은 원하는 값을 찾아서 수행하거나 혹은 알고리즘만으로 (feature,corner detction) 으로 수행
    
    // 다음시간 gradient decent( 경사 하강법) 으로 아래 데이터 최적화 해보기

    // 여기서 만약에 특정한 하나의 고양이 이미지의 (r,g,b)를 x_data 주어짐
    // 그리고 여기서 특정한 하나의 강아지 이지미의 (r,g,b)를 y_data로 주어짐
    // 고양이와 강아지의 이미지 관계 선형 구축 될 수 있음
    // 고양이 이미지에 가우시안 필터 적용 혹은 bmp파일로 만들어요 -> 노이즈 생성
    // 관계 선형 Linear 를 적용 하면 어떤 이미지가 나올까요? 

    // 과제 : x,y 바꿔보고 조작 해보기! 

    // 베이스라인이 주어지고 어떤 학습데이터와 정답데이터가 주어짐
    // 거기서 정답데이터를 유추하는 선형 linear 
    // 장점 : 이해도가 있는 작업을 수행 할 수 있다!
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