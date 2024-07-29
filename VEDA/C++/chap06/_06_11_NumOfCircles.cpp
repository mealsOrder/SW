#include<iostream>

using namespace std;

class Circle{
private:
    int r;
    static int numOfCircles;
public:
    Circle(int r = 1);
    ~Circle() { numOfCircles--;}
    double getArea(){
        return r*r*3.14;
    }
    static int getNumOfCircles(){
        return numOfCircles;
    }

};

Circle::Circle(int r)
{
    this->r = r;
    numOfCircles++;
}

int Circle::numOfCircles = 0;

int main(){

    Circle *p = new Circle[10];
    cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << '\n';

    delete []p;
    cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << '\n';

    Circle a;
    cout << "생존하고 있는 원의 개수 = " << a.getNumOfCircles() << '\n';
    
    Circle b;
    cout << "생존하고 있는 원의 개수 = " << b.getNumOfCircles() << '\n';


    return 0;
}