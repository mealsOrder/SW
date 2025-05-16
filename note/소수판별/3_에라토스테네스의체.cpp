#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<bool>getPrime(int x){
    vector<bool>isPrime(x+1,true);
    isPrime[0]=isPrime[1] = false;

    for(int i=2;i*i<=x;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=x;j+=i){
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<bool>prime = getPrime(N);
    for(int i=0;i<=N;i++){
        if(prime[i]) cout << i << ' ';
    }

    return 0;
}