#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<random>
using namespace std;

// Gradient Descent
// 1. 모든 에러 값을 반영 것
// 2. 제약 조건 없이 최적화를 진행
// f(x) : LossFunction 
// a : learning_rate
// Weight - af'(x)  

// 제약 조건이 있을 경우 제약 조건을 없앨 수 있다
// 방법 1 Barrier Function  : 
// 방법 2 Lagrange Function : 
// 제약조건 두개를 합친다! >> 제약조건을 없앤다.

// Lagrange Function
// x^2+y^2 = 0
// x+y-1 = 0

//x^2 + y^2 ㅅ(x+y-1)
// >> fL(x,y,ㅅ)

// Gradient Descent 의 방법론 (최적화)
// gkdisdhfl1
// 1. batch Gradient Descent (BSD)
// 2. Stochastic Gradient Descent (SGD)
//  - 랜덤하게 하나씩 뽑아서 로스를 구해본다.(통계,확률 느낌)
//  - 속도 측면에서 효율 적임
//  - 스텝 사이즈가 큼
//  - 조금더 공부 필요... 기본 개념
// 3. Momentum
//  - SGD에서 스텝 사이즈가 큰 것을 해결하기 위해
//  - 이전 메모리 벡터를 활용해서 최적화
//  - 모맴텀 상수는 0~1 사이의 수
// 4. Adagrad
//  - learning rate를 다르게 줘서 최적화
//  - local minimun 효율적으로 찾기
// 5. RMSProps
// 6. Adam ***
//  - Momentum + Adagrad 느낌

// Gradient Descent 의 한계
// - 내가 구한 로스가 이포크가 충분하지 않아 최저라고 착각할 수 있다.
// - 너무 많은 데이터 셋 ... 안정성은 좋지만 실질적으로 인공지능에 쓸 수 없음


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    
    return 0;
}