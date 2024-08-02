#include<iostream>
#include<string>
using namespace std;
// 소멸자를 가상 함수로 선언하여, 
// 객체 소멸시 기본 클래스와 파생 클래스의 소멸자가
// 모두 실행 되는 정상적인 소멸 과정을 보여 준다.
class Base{
public:
    virtual ~Base(){cout << "~Base\n";}
};

class Derived : public Base{
public:
    virtual ~Derived(){
        cout << "~Derived\n";
    }
};
int main(){
    Derived *dp = new Derived();
    Base *bp = new Derived();

    delete dp;
    delete bp;
    return 0;
}