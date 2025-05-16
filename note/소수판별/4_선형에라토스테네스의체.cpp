#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>linearSieve(int n){
    vector<int>primes;
    vector<int>minFactor(n+1,0); // 최소 소인수

    for(int i=2;i<=n;i++){
        if(minFactor[i] == 0){
            minFactor[i] = i;
            primes.push_back(i);
        }
        for(int p:primes){
            if(p>minFactor[i]|| i*p>n)break;
            minFactor[i*p]=p;
        }
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int>prime = linearSieve(N);
    for(int p:prime) cout << p <<' ';

    return 0;
}