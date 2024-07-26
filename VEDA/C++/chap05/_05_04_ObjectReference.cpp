#include<iostream>
using namespace std;

class Circle
{
    int radius;
public:
    Circle(){radius = 1;}
    Circle(int r) { this->radius = r;}
    void setRadius(int r) {this->radius = r;}
    double getArea() { return 3.14*radius*radius; }
};

int main()
{
    Circle c;
    Circle &refc = c; // Circle 객체에 대한 참조 변수 refc선언
    refc.setRadius(10);
    cout << refc.getArea() << " " << c.getArea() << '\n';

    return 0;
}