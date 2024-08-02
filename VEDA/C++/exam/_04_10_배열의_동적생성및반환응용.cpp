#include<iostream>
using namespace std;
/**
 * p184
 * 원의 개수를 입력받고 Circle 배열을 동적 생성해라
 */
class Circle{
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle(){ };
    void setRadius(int r) { radius = r; }
    double getArea() { return radius*radius*3.14; }
};

Circle::Circle(){
    radius = 1;
}
int main(){
    cout << "생성하고픈 원의 개수";
    int n,radius;
    cin >> n;
    if(n<=0) return 0;
    Circle *pArr = new Circle[n];
    for(int i=0;i<n;i++){
        cout << "원" << i+1 << ": ";
        cin >> radius;
        pArr[i].setRadius(radius);
    }
    int cnt=0;
    Circle *p = pArr;
    for(int i=0;i<n;i++){
        cout << p->getArea() << " ";
        if(p->getArea() >= 100 && p->getArea()<=200)cnt++;
        p++;
    }

    cout << "\n면적이 100~200 사이인 원의 개수는" << cnt << '\n';
    delete[] pArr;

    return 0;
}