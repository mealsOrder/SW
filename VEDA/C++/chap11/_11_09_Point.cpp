#include<iostream>
using namespace std;

class Point{
private:
    int x,y;
public:
    Point(int x=0,int y=0){
        this->x=x;
        this->y=y;
    }
    friend ostream& operator<<(ostream& os,Point a);

};

ostream& operator<<(ostream& os,Point a){
    os << "(" << a.x << "," << a.y <<")";
    return os;
}

int main(){
    Point p(3,5);
    cout << p << '\n';

    Point q(100,1), r(100,2);
    cout << q << " " << r << '\n';
    return 0;   

}