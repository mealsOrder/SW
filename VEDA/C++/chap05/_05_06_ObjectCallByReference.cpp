#include<iostream>

using namespace std;

class Circle{
private:
    int radius;
public:
    Circle()
    { 
        radius = 1;
        cout << "디폴트 생성자 실행 radius = " << radius << '\n';
    }
    Circle(int r)
    {
        this->radius = r;
        cout << "매개변수 생성자 실행 radius = " << radius << '\n';
    }
    ~Circle() { cout << "소멸자 실행 radius = " << radius << '\n'; }
    double getArea()
    {
        return 3.14*radius*radius;
    }
    int getRadius()
    {
        return radius;
    }
    void setRadius(int r)
    {
        this->radius = r;
    }
};

void increse(Circle &c)
{
    int r = c.getRadius();
    c.setRadius(r+1);
}

int main()
{
    Circle waffle(30);
    increse(waffle);
    cout << "증가시킨 반지름 : " << waffle.getRadius() << '\n';
}