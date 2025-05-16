#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isPrime(int x){
    if(x<2) return false;
    for(int i=2;i<x;i++){
        if(x%i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0;i<=N;i++){
        if(isPrime(i)) cout << i << ' ';
    }

    return 0;
}