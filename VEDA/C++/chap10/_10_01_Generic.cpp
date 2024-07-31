#include<iostream>
using namespace std;
class Circle{
    int radius;
public:
    Circle(int radius=1){
        this->radius = radius;
    }
    int getRadius(){
        return radius;
    }
};

template <class T>
void mySwap(T &a, T &b){
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}
int main(){
    int a=4,b=5;
    mySwap(a,b);
    cout << "a="<<a << ", " << "b=" << b << '\n';

    double c=0.3,d=12.5;
    cout << "c="<<c << ", " << "d=" << d << '\n';

    
    return 0;
}