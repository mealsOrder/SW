#include<iostream>
#include<string>
using namespace std;
class Circle
{
private:
    int radius;
public:
    Circle()
    {
        radius = 1;
        cout << "디폴트 생성자 실행 radius = " << radius << '\n';
    }
    Circle(int radius)
    {
        this->radius = radius;
        cout << "매개변수 생성자 실행 radius = " << radius << '\n';
    }
    ~Circle()
    {   
        cout << "소멸자 실행 radius = " << radius << '\n';
    }
    void setRadius(int radius)
    {   
        this->radius = radius;
    }
    double getArea()
    {
        return 3.14*radius*radius;
    }    

};

Circle getCircle()
{
    Circle tmp(30);
    return tmp;
}

int main()
{
    Circle c;
    cout << c.getArea() << '\n';

    c = getCircle(); // tmp 객체가 c에 복사. c의 radius는 30이 된다!
    cout << c.getArea() << '\n';
    return 0;
}