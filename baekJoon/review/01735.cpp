#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int gcd(int a,int b){
    while(b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,c,d; // a/b + c/d
    cin >> a>>b>>c>>d;
    int up = a*d + b*c;
    int down = b*d;
    cout << up / gcd(up,down) << " " << down/gcd(up,down);
	return 0;
}