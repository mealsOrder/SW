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
    Power operator++(int x);
};
void Power::show(){
    cout << "kick= " << kick << " " << "punch= " << punch << '\n';
}

Power Power::operator++(int x){
    Power tmp = *this;
    kick++;
    punch++;
    return tmp;
}

int main(){
    Power a(3,5), b(5,5),c;

    a.show();
    b.show();
    c.show();
    c = a++;
    a.show();
    c.show();
    return 0;
}