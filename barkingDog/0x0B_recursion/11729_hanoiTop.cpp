#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void hanoi(int a,int b, int n){
    if(n==1){
        cout << a << ' ' << b << '\n';
        return;
    }
    hanoi(a,6-a-b,n-1);
    cout << a << ' ' << b << '\n';
    hanoi(6-a-b,b,n-1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int K;
    cin >> K;
    cout << pow(2,K) -1 << '\n';
    hanoi(1,3,K);
    return 0;
}