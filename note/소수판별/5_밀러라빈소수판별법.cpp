#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

ll modPow(ll base, ll exp, ll mod){
    ll res = 1;
    base %= mod;
    while(exp>0){
        if(exp&1) res =(__int128_t)res * base % mod;
        base =(__int128_t)base * base % mod;
        exp >>= 1;
    }
    return res;
}

bool millerRabin(ll n, ll a){
    if(n % a == 0) return false;
    ll d = n - 1;
    while(d % 2 == 0) d /= 2;

    ll t = modPow(a, d, n);
    while(d != n - 1 && t != 1 && t != n - 1){
        t =(__int128_t)t * t % n;
        d *= 2;
    }
    return t == n - 1 || d % 2 == 1;
}

bool isPrime(ll n){
    if(n < 2) return false;
    for(ll a :{2, 3, 5, 7, 11, 13, 17}){
        if(n == a) return true;
        if(!millerRabin(n, a)) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;

    if(isPrime(N)) cout << "소수입니다\n";
    else cout << "소수가 아닙니다\n";
    return 0;

    return 0;
}