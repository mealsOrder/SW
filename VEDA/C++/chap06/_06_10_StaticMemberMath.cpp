#include<iostream>

using namespace std;

class Math{
public:
    static int abs(int a){
        return a>0?a:-a;
    }
    static int max(int a,int b){
        return (a>b)?a:b;
    }
    static int min(int a,int b){
        return (a>b)?b:a;
    }
};

int main(){
    // 스테틱 멤버를 부르는 법

    // 1. 클래스 이름으로 부르기
    cout << Math::abs(-5) << '\n';
    cout << Math::max(10,5) << '\n';
    cout << Math::min(-3,-9) << '\n';

    // 2. 객체로 부르는 법
    Math m;
    cout << m.abs(-5) << '\n';
    cout << m.max(10,5) << '\n';
    cout << m.min(-3,-9) << '\n';
    return 0;   
}