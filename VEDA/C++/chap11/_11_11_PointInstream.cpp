#include<iostream>
using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(int x=0,int y=0){
        this->x=x;
        this->y=y;
    }
    friend ostream& operator<<(ostream& os, Point p);
    friend istream& operator>>(istream& is, Point &p);
};

ostream& operator<<(ostream& os,Point p){
    os<< "(" << p.x << "," << p.y << ")";
    return os;
}

istream& operator>>(istream& is, Point &p){
    cout << "x 좌표: ";
    is >> p.x;
    cout << "y 좌표: ";
    is >> p.y;
    return is;
}

int main(){
    Point p;
    cin >> p;
    cout << p;
    return 0;   

}