#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1){
        int a,b,c;
        int sum = 0;
        cin >> a>> b>>c;
        sum = a+b+c;
        if( a==0&&b==0&&c==0) break;
        if( sum - max({a,b,c}) > max({a,b,c})){
            if(  a==b && b==c&& a==c ) cout << "Equilateral\n";
            else if(  a==b||b==c||a==c ) cout << "Isosceles\n";
            else cout << "Scalene\n";
        }
        else{
            cout << "Invalid\n";
        }
    }

    return 0;
}