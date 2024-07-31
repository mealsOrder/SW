#include<iostream>
using namespace std;
// 중복된 함수를 템플릿 함수보다 우선하여 바인딩!
template <class T>
void prt(T a [], int n){
    for(int i=0;i<n;i++){
        cout << a[i] << '\t';
    }
    cout << '\n';
}
void prt(char a [], int n){
    for(int i=0;i<n;i++){
        cout << (int)a[i] << '\t';
    }
    cout << '\n';
}
int main(){
    int x[] = {65,66,67,68,69};
    double d[5] = {1.1,2.2,3.3,4.4,5.5};

    prt(x,5);
    prt(d,5);

    char c[5] = {'A','B','C','D','E'};
    prt(c,5);
    return 0;
}