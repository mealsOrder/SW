#include<iostream>

using namespace std;
class Circle
{
private:
    int radius;
public:
    Circle(const Circle& c)
    { // 복사 생성자 선언
        this->radius = c.radius;
        cout << "복사 생성자 실행 radius = " << radius << '\n';
    }
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
};
int main()
{
    Circle src(30);   // src 객체의 일반 생성자 호출
    Circle dest(src); // dest 객체의 복사 생성자 호출

    cout << "원본의 면적 = " << src.getArea() << '\n';
    cout << "사본의 면적 = " << dest.getArea() << '\n';

    return 0;
}