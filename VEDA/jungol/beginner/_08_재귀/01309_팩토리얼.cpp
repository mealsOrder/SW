#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MX = 16;
long long dp[MX];

long long func(int x){
    if(x <=1) return 1;
    return x*func(x-1);
}

int main(){
	long long N;
    cin >> N;
    dp[0] = 1;
    dp[1] = 1;

    for(int i = N;i>0;i--){
        if( i==1) cout << "1! = 1\n";
        else cout << i << "! = " << i << " * " << (i-1) << "!\n"; 
    }
    cout << func(N);

	return 0;
}