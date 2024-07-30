#include<iostream>
#include<string>
using namespace std;

// protected 상속
class Base{
private:
    int a;
protected:
    void setA(int a){this->a = a;}
public:
    void showA(){cout << a;}
};

class Derived : protected Base{
private:
    int b;
protected:
    void setB(int b){this->b = b;}
public:
    void showB(){cout << b;}
};

int main(){

    // 오류 나는 라인 찾아보기
    // 컴파일 시키지 말고...
    Derived x;
    x.a = 5;
    x.setA(10);
    x.showA();
    x.b = 10;
    x.setB(10);
    x.showB();
    return 0;
}