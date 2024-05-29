#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int factorial(int x){
    if(x <= 1) return 1;
    else return x*factorial(x-1);
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >>N;
    int ans = factorial(N);
    cout << ans;
    return 0;
}