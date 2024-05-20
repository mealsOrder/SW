#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

    int N,ans=0;
    cin >> N;

    for(int i=1;i<=N;i++){
        if(i>=sqrt(N)){
            ans = i;
            cout << ans << endl;
            break;
        }
    }

    return 0; 
}