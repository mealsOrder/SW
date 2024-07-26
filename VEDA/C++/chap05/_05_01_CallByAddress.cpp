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
        cout << "생성자 실행 radius = " << radius << '\n';
    }
    Circle(int radius)
    {
        this->radius = radius;
        cout << "생성자 실행 radius = " << radius << '\n';
    }
    ~Circle()
    {
        cout << "소멸자 실행 radius = " << radius << '\n';
    }
    double getArea()
    {
        return 3.14*radius*radius;
    }    
    int getRadius()
    {
        return radius;
    }
    void setRadius(int radius)
    {   
        this->radius = radius;
    }

};

void increase(Circle *p)
{
    int r = p->getRadius();
    p->setRadius(r+1);
}

int main()
{
    Circle waffle(30);
    increase(&waffle);
    cout << waffle.getRadius() << '\n';

    return 0;
}