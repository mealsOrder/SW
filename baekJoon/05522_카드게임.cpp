#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long s = 0;
    for(int i=0;i<5;i++){
        long long a;
        cin >> a;
        s += a;
    }
    cout << s << '\n';
    return 0;
}