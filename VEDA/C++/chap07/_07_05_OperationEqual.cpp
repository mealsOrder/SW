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
    bool operator==(Power op2);
};
void Power::show(){
    cout << "kick= " << kick << " " << "punch= " << punch << '\n';
}
bool Power::operator==(Power op2){
    if(kick == op2.kick && punch==op2.punch) return true;
    else return false;
}
int main(){
    Power a(3,5), b(3,5),c;
    a.show();
    b.show();
    if(a==b) cout << "equal\n";
    else cout << "not equal\n";
    return 0;
}