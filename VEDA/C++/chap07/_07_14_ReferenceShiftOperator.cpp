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
    Power& operator<<(int n);
};
void Power::show(){
    cout << "kick= " << kick << " " << "punch= " << punch << '\n';
}

Power& Power::operator<<(int n){
    kick+=n;
    punch+=n;
    return *this;
}

int main(){
    Power a(1,2);
    a << 3 << 5 << 6;
    a.show();
    return 0;
}