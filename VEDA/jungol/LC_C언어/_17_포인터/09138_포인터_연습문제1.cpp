#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a = 10;
    int *p = &a;
    //&a = 1245052;

    cout << "a = " << a<<", &a = 1245052" << '\n';
    cout << "*p = " << *p<<", p = 1245052" << '\n';
    return 0;
}