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
    bool operator! ();
};
void Power::show(){
    cout << "kick= " << kick << " " << "punch= " << punch << '\n';
}

bool Power::operator!(){
    if(kick == 0 && punch == 0) return true;
    else return false;
}

int main(){
    Power a(0,0), b(5,5),c;
    if(!a) cout << "a 파워 0\n";
    else cout << "a 파워 0 아님\n"; 
    if(!b) cout << "b 파워 0\n";
    cout << "b 파워 0 아님\n";
    return 0;
}