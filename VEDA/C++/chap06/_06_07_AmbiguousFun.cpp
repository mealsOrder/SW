#include<iostream>

using namespace std;

float square(float a){
    return a*a;
}

double square(double a){
    return a*a;
}

int add(int a,int b){
    return a+b;
}

int add(int a,int &b){
    b = b+a;
    return b;
}

void msg(int id){
    cout << id<<'\n';
}

void msg(int id,string s=""){
    cout << id << ":" << s << '\n';
}
int main(){
    // 1. 형 변환으로 인한 모호성
                        // 3  = int
                        // 3L = double
                        // 3.0f = float 
    cout << square(3.0);// 3.0 = double
    //cout << square(3); // 중복된 함수에 대한 모호한 호출로서, 컴파일 오류


    // 2. 참조 매개변수로 인한 모호성
    int s = 10, t=20;
    //cout << add(s,t); // 참조 매개변수로 인해 함수 호출이 모호함, 컴파일 오류


    // 3. 디폴트 매개 변수로 인한 모호성
    msg(5,"Good Morning"); // 정상 컴파일. 두번째 msg() 호출
    //msg(6); // 함수 호출 모호, 컴파일 오류

    // 틀린 함수 중복
    // 배열 이름은 포인터이기 때문에, 다음 두 한수는 같은 함수로서, 공존할 수 없다!
    // void f(int a[]);
    // void f(int *a);

    return 0;   
}