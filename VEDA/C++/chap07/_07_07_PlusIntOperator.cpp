#include<iostream>
using namespace std;
class Power{
private:
    int kick;
    int punch;
public:
    Power(int kick=0,int punch=0){
        this->kick=kick;
        this->punch=punch;
    }
    void show();
    Power operator+(int op2);
};
void Power::show(){
    cout << "kick= " << kick << " " << "punch= " << punch << '\n';
}

Power Power::operator+(int op2){
    Power tmp;
    tmp.kick = kick+op2;
    tmp.punch = punch+op2;
    return tmp;
}

int main(){
    Power a(3,5), b(4,6),c;
    a.show();
    b.show();
    b = a+3;
    c = a+2;
    b.show();
    c.show();
    return 0;
}