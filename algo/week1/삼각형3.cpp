#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    int N;
    cin >> N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N-i;j++){
            cout << " ";
        }
        

        for(int j=N-1;j>=N-i;j--){
            cout << "*";
        }

        for(int j=N-2;j>=N-i;j--){
            cout <<"*";
        }

        cout << '\n';

    }

    return 0; 
}