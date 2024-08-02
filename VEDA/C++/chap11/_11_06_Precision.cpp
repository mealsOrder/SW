#include<iostream>
using namespace std;


void showW(){
    cout.width(10);
    cout << "hello\n";
    cout.width(5);
    cout << 12 << "\n"; 

    cout << '%';
    cout.width(10);
    cout << "Korea/" << "Korea/" << "Korea/\n"; 
}
int main(){
    showW();
    cout << '\n';

    cout.fill('^');
    showW();
    cout<<'\n';

    cout.precision(5);
    cout << 11./3.  <<'\n';

    return 0;   
}