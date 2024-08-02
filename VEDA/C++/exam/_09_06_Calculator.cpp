#include<iostream>
#include<string>
using namespace std;
class Calculator{
public:
    virtual int add(int a,int b) = 0;
    virtual int sub(int a,int b) = 0;
    virtual double avg(int a[],int size) = 0;
    // 위 avg함수의 매개변수를 a[] 사용하지 않고 포인터로 구현해보기!
};

class GoodCalc : public Calculator{
public:
    int add(int a,int b){return a+b;}
    int sub(int a,int b){return a-b;}
    double avg(int a[],int size){
        double sum = 0;
        for(int i=0;i<size;i++){
            sum += a[i];
        }
        return sum/size;
    }
};

int main(){
    int a[] = {1,2,3,4,5};
    Calculator *p = new GoodCalc();
    cout << p->add(2,3) << '\n';
    cout << p->sub(2,3) << '\n';
    cout << p->avg(a,5) << '\n';
    delete p;
    return 0;
}