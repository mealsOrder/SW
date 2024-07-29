#include<iostream>
using namespace std;

class Power{
private:
    int kick;
    int punch;
public:
    Power(int kick=0,int punch=0){
        this->kick = kick;
        this->punch=punch;
    }
    void show();
    // + 연산자 함수 생성
    Power operator+ (Power op2); // Power& op2 로 해도 됨
};

void Power::show(){
    cout << "kick= " << kick << " " << "punch= " << punch << '\n';
}

// +연산자 멤버 함수 구현
Power Power::operator+(Power op2){
    Power temp;
    temp.kick = this->kick+op2.kick;
    temp.punch = this->punch+op2.punch;
    return temp;
}
int main(){
    Power a(3,5), b(4,6),c;
    c=a+b;
    a.show();
    b.show();
    c.show();
    c = a.operator+(b);
    c.show();

    return 0;
}