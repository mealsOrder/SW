#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long GCD(long long a, long long b){
    long long r = a%b;
    while(r != 0 ){
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long A,B;

    cin >> A >> B;

    long long ans = 0;
    
    if( A>= B)ans = A*B/GCD(A,B);
    else ans =A*B/GCD(B,A);
    
    cout << ans << '\n';

    return 0;
}