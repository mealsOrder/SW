#include<iostream>

using namespace std;

void f(char c = '*' , int line=25){
    for(int i=0;i<line;i++){
        cout << c;
    }
    cout << '\n';
}
int main(){

    f();
    f('%');
    f(' ',10);
    f('@',5);
    return 0;   
}