#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    int N,M;
    cin >> N>>M;

    if(N>M){
        int temp=N;
        N=M;
        M=temp;
    }

    
    for(int i=N;i<=M;i++){
        int cnt = 0;
        for(int j=2;j<=M;j++){
            
            if(i%j == 0){
                cnt++;
                
            }
            if(cnt>=2) break;

        }
        if(cnt == 1){
            cout << i << " ";
        }
    }
    return 0; 
}