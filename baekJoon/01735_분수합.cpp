#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int findGDC(int a,int b){
    int r = a%b;
    while(r!=0){
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,d; // a/b + c/d
    cin >> a>>b>>c>>d;
    int up=0;
    int down=0;
    up = a*d + c*b;
    down = b*d;
    cout << up/findGDC(down,up) << " " << down/findGDC(down,up);
    return 0;
}