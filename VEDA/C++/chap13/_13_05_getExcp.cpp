#include<iostream>
using namespace std;
int getExp(int base, int exp){
    if(base<=0||exp<=0){
        throw "err";
    }
    int val = 1;
    for(int n=0;n<exp;n++)
        val = val*base;
    return val;

}
int main(){

    int v=0;
    try{
        v = getExp(2,3);
        cout << "2^3=" << v << '\n';

        v = getExp(2,-3);
        cout << "2^-3=" << v << '\n';
    }catch(const char *s){
        cout << "exception !! " << s << '\n';
    }
    return 0;
}