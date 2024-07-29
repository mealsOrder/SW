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
    Power& operator++();
};
void Power::show(){
    cout << "kick= " << kick << " " << "punch= " << punch << '\n';
}

Power& Power::operator++(){
    kick++;
    punch++;
    return *this;
}

int main(){
    Power a(3,5), b(4,6),c;
    a.show();
    b.show();
    b = ++a;
    b.show();
    c = ++b;
    c.show();
    return 0;
}