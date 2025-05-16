#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;

bool isPrime(int num){
    if(num < 2)return false;
    for(int i =2;i*i<=num;i++){
        if(num % i == 0)return false;
    }
    return true;
}

void DFS(int num, int jari){

    if(jari == N){
        cout << num << '\n';
        return;
    }

    for(int i=1;i<=9;i++){
        int nx = num * 10 + i;
        if(isPrime(nx)){
            DFS(nx,jari+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i=2;i<10;i++){
        if(isPrime(i)){
            DFS(i,1);
        }
    }

    return 0;
}
