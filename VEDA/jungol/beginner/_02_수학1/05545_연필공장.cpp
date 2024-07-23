#include<iostream>

using namespace std;
long P,V,K;

// LCM = a*b/GCD ;
long long GCD(long long a,long long b){
    long long r = a%b;
    while(r != 0){
        a=b;
        b=r;
        r = a%b;
    }
    return b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> P>>V>>K;
    P+=1;
    V+=1;
    long long B = K / (P*V/GCD(P,V));
    long long A = K-(K/P + K/V) + B;
    long long C = K/V - B;
    long long D = K/P -B;
    cout << A << " " << B << " " << C << " " << D;
    return 0;
}