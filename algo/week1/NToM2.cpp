#include <iostream>

using namespace std;

int main() {

    int N,M;
    cin >> N >>M;

    int cnt = 0;
    for(int i=N;i<=M;i++){
        cnt++;
        cout << i << " ";
        if(cnt%8==0){
            cout << '\n';
        }
    }

    return 0; 
}