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
    friend Power& operator++(Power& op); // ++전위
    friend Power operator++(Power& op,int x); // 후위++
};
void Power::show(){
    cout << "kick= " << kick << " " << "punch= " << punch << '\n';
}

Power& operator++(Power& op){
    op.kick++;
    op.punch++;
    return op;
}

Power operator++(Power& op,int x){
    Power tmp = op;
    op.kick++;
    op.punch++;
    return tmp;
}

int main(){
    Power a(3,5), b(4,6),c;

    a.show();
    b.show();
    b = ++a;
    a.show();
    b.show();
    b = a++;
    a.show();
    b.show();
    return 0;
}