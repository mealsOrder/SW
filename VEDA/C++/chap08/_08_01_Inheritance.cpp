#include<iostream>
#include<string>
using namespace std;

class Point{
private:
    int x,y;
public:
    void set(int x,int y){
        this->x = x;
        this->y = y;
    }
    void showPoint(){
        cout << "(" << x << "," << y << ")\n";
    }
};

class ColorPoint : public Point{
    string color;
public:
    void setColor(string color){
        this->color = color;
    }
    void showColorPoint();
};

void ColorPoint::showColorPoint(){
    cout << color << ":";
    showPoint();
}

int main(){
    Point p;
    ColorPoint ccp;
    ccp.set(3,4);
    ccp.setColor("Yello");
    ccp.showColorPoint();

    ColorPoint cp;
    ColorPoint *pDer;
    Point* pBase = &cp; // 업 캐스팅

    // 다운 캐스팅 시 강제 타입변환 필요!
    pDer = (ColorPoint*)pBase; // 다운 캐스팅
    pDer->setColor("RED");
    pDer->showColorPoint();


    return 0;
}