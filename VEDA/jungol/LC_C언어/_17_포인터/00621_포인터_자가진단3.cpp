#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin >> a >> b;
    int *pa = &a;
    int *pb = &b;
    cout << *pa << " + " << *pb << " = " << *pa+*pb<<'\n';
    cout << *pa << " - " << *pb << " = " << *pa-*pb<<'\n';
    cout << *pa << " * " << *pb << " = " << *pa * *pb<<'\n';
    cout << *pa << " / " << *pb << " = " << *pa / *pb;
    return 0;
}