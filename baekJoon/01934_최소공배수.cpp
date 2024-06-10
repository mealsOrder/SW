#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int findGCD(int a, int b){
    int r = a%b;

    while( r!= 0){
        a = b;
        b = r;
        r = a%b;
    }

    return b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    int gdc;
    while(T--){
        int a,b;
        gdc = 0;
        cin >> a >> b;
        if(a>=b) gdc = findGCD(a,b);
        else gdc = findGCD(b,a);

        cout << a*b/gdc << '\n';
    }

    return 0;
}