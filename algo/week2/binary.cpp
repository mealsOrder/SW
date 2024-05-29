#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
string toBinary(int n) {
    if (n == 0) return "0";
    else if (n == 1) return "1";
    else return toBinary(n / 2) + to_string(n % 2);
}
int main(){
    int N;
    cin >>N;
    string ans = toBinary(N);
    cout << ans;
    return 0;
}