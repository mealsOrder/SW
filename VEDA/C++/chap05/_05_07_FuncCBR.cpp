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
    ~Circle() 
    {
        cout << "소멸자 실행 radius = " << radius << '\n';
    }
    double getArea()
    {
        return 3.14*radius*radius;
    }
    void setRadius(int r)
    {
        this->radius = r;
    }
};

void readRadius(Circle &c)
{
    int a;
    cout << "정수 값으로 반지름을 입력: ";
    cin >> a;
    c.setRadius(a);
}

int main()
{
    Circle d;
    readRadius(d);
    cout << "면적 : " <<d.getArea() << '\n';
}