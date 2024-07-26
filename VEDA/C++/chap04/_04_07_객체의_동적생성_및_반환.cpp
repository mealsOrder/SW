#include<iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle();
    void setRadius(int r) { radius = r; }
    double getArea() {
        return radius*radius*3.14;
    }
};

Circle::Circle(){
    radius = 1;
    cout << "생성자 실행 radius = " << radius << '\n';
}
Circle::Circle(int r){
    radius = r;
    cout << "생성자 실행 = " << radius << '\n';
}
Circle::~Circle(){
    cout << "소멸자 실행 radius = " << radius << '\n';
}
int main(){
    Circle *p,*q;
    p = new Circle;
    q = new Circle(30);
    cout << p->getArea() << '\n' << q->getArea() << '\n';
    delete p;
    delete q;   
    return 0;
}