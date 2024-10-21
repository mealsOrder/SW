#include<iostream>
#include<algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a,b,c;
    cin >> a>>b>>c;

    int sum = a+b+c;
    if(sum != 180) cout << "Error\n";
    else {
        if(a==b && b == c && a== c) cout << "Equilateral\n";
        else if ( a==b || b == c || a== c) cout << "Isosceles\n";
        else{
            cout << "Scalene\n";
        }
    }
    return 0;
}