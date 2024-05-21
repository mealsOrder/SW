#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int arr[16];
int main() {
    
    int N;
    cin >>N;

    arr[0]=4;
    for(int i=1;i<=N;i++){
        int sq = sqrt(arr[i-1]) + pow(2,i-1);
        arr[i] = pow(sq,2);
    }
    cout << arr[N] << endl;
    return 0;
}