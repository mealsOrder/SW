#include<iostream>
using namespace std;

template<class T>
T bigger(T a,T b){
    if(a>b) return a;
    else return b;
}

int main(){
    int a = 20, b= 50;
    char c='a',d='z';    
    cout << "bigger(20,5)의 결과는 " << bigger(a,b) << '\n';
    cout << "bigger('a','z')의 결과는 " << bigger(c,d) << '\n';
    return 0;
}