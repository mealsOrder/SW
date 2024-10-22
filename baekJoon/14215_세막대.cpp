#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[3];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    
    if(a[0] + a[1] > a[2]) cout << a[0] + a[1] + a[2];
    else cout << (a[0] + a[1]) * 2 - 1;

    return 0;
}