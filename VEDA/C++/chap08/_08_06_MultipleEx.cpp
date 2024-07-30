#include<iostream>
#include<string>
using namespace std;


class Base{
private:
    int a;
protected:
    void setA(int a){this->a = a;}
public:
    void showA(){cout << a;}
};

// private 상속
class Derived : protected Base{
private:
    int b;
protected:
    void setB(int b){this->b = b;}
public:
    void showB(){
        setA(5); // ?
        showA(); // ?
        cout << b;
    }
};

// private 상속
class GrandDerived : private Derived{
private:
    int c;
protected:
    void setAB(int x){
        setA(x); // ?
        showA(); // ?
        setB();  // ?
    }
public:
    void showB(){cout << b;}
}
int main(){

    // ? 에 오류가 나는지 안나는지 체크
    
    return 0;
}