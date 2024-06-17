#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int STR,DEX,INT,LUK,N;
    cin >> STR>>DEX>>INT>>LUK>>N;
    int sum = STR+DEX+INT+LUK;
    double avg = (double)sum / 4;
    if(N - avg <= 0) cout << "0\n";
    else{
        cout << (N-avg)*4 << '\n';
    }
    return 0;
}