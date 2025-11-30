#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 46;

int A[MX];
int B[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int K;
    cin >> K;

    A[0] = 1;
    A[1] = 0;

    B[0] = 0;
    B[1] = 1;
    for(int i=2;i<=K;i++){
        A[i] = A[i-1] + A[i-2];
        B[i] = B[i-1] + B[i-2];
    }


    cout << A[K] << ' ' << B[K] << '\n';
    return 0;
}