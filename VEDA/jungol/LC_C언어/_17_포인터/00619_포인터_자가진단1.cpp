#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin >> a >> b;

    int *p = &a;
    cout << "a = " << a << ", *p = " << *p << '\n';
    int *pp = &b;
    cout << "a = " << b << ", *p = " << *pp << '\n';
    
    cout << "a = " << a+b << ", *p = " << *p+*pp << '\n';

    cout << "a = " << (a+b)*2 << ", *p = " << (*p+*pp)*2 << '\n';

    cout << "a = " << (a+b)*2 -1 << ", *p = " << (*p+*pp)*2 -1;

    return 0;
}
