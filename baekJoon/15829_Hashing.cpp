#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const long long MOD = 1234567891;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int L;
    long long r = 1;
    long long H=0;
    cin >> L;
    for(int i=0;i<L;i++){
        char a;
        cin >> a;
        H += ((a - 96) * r)%MOD;
        r = (r*31)%MOD;
    }
    cout << H % MOD;
    return  0;
}