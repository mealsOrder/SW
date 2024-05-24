#include<iostream>

using namespace std;
int factorial(int x){
    if(x<=1)return 1;
    else{
        return x*factorial(x-1);
    }
}
int main() {
    
    int N,K;
    cin >>N>>K;
    int res=1;
    for(int i=1;i<=K;i++){
        res *= N;
        N--;
    }
    cout << res/factorial(K);

    return 0;
}