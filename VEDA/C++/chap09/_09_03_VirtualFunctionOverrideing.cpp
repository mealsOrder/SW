#include<iostream>
#include<string>
using namespace std;
class Base{
public:
    virtual void f(){cout << "Base::f() called\n";}
};

class Derived : public Base{
public:
    virtual void f(){cout << "Derived::f() called\n";}
};

class GrandDerived : public Derived{
public:
    virtual void f(){cout << "GrandDerived::f() called\n";}
};
int main(){
    GrandDerived g,*gp;
    Base *bp;
    Derived *dp;
    bp = dp = gp = &g;  // 모든 포인터가 객체 g를 가리킴

    bp->f();    // Base의 멤버 호출 --> 결과는?
    dp->f();    // Derived의 멤버 호출 --> 결과는?
    gp->f();    // GrandDerived의 멤버 호출 --> 결과는?

    // 결과는 셋다 GrandDerived::f() 호출됨

    return 0;
}