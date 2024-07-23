#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin >> a;
    int *p = &a;
    cout << *p/10 << "..." << *p%10;
    return 0;
}