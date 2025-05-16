#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int>v;
vector<bool>getPrime(int x){
    vector<bool>isPrime(x+1,true);
    isPrime[0]=isPrime[1]=0;
    
    for(int i=2;i<=x;i++){
        if(isPrime[i]){
            for(int j=i;j<=x;j+=i){
                if(isPrime[j]){
                    isPrime[j] = false;
                    v.push_back(j);
                }
                else continue;
            }
        }

    }
    return isPrime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,K;
    cin >> N >>K;
    vector<bool>primes = getPrime(N);

    for(int i=0;i<v.size();i++){
        if(i == K-1){
            cout << v[i] << '\n';
            break;
        }
    }
    return 0;
}