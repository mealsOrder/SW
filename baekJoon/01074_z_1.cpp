#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int N,R,C;
int func(int n,int r, int c){
    int half = pow(2,n-1);
    if(n == 0) return 0;
    if(r<half && c<half) return func(n-1,r,c);
    if(r<half && c>=half) return half*half+func(n-1,r,c-half);
    if(r>=half && c<half) return 2*half*half+func(n-1,r-half,c);
    //if(r>=half && c>=half)
    return 3*half*half+func(n-1,r-half,c-half);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N>>R>>C;
    cout << func(N,R,C);

    return 0;
}