#include<iostream>
#include<iomanip>
using namespace std;

ostream& fivestar(ostream& out){
    return out << "*****\n";
}

ostream& arrow(ostream& out){
    return out << "----->\n";
}
ostream& beep(ostream& out){
    return out << '\a';
}
int main(){
    cout << " Bell" << beep;
    cout << arrow;
    cout << fivestar;

    return 0;   

}