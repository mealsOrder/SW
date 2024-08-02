#include<iostream>
#include<string>
using namespace std;
// 추상 클래스
class Calculator{
    void input(){
        cout << "정수 2개를 입력하세요>> ";
        cin >> a >> b;
    }
protected:
    int a,b;
    virtual int calc(int a,int b) = 0; // 순수 가상함수
public:
    void run(){
        input();
        cout << "값은 " << calc(a,b) << '\n';
    }
};

class Adder : public Calculator{
    int calc(int a,int b){
        return a+b;
    }
};

class Sub : public Calculator{
    int calc(int a,int b){
        return a-b;
    }
};

int main(){
    Adder a;
    Sub s;

    a.run();
    s.run();
    return 0;
}