#include<iostream>
#include<string>
using namespace std;
class Shape{
public:
    virtual void draw(){
        cout << "--Shape--\n";
    }
};

class Circle : public Shape{
public:
    int x;
    virtual draw(){
        Shape::draw(); // 부모클래스의 draw() 호출
        cout << "Circle\n";
    }
};

int main(){
    Circle c;
    Shape* pShape = &c;

    pShape->draw(); // 동적 바인딩 발생. draw() 가 virtual이므로
    pShape->Shape::draw(); // 정적 바인딩 발생. 범위 지정 연산자로 인해~ 

    return 0;
}