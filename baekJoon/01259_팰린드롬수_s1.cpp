#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main() {
    
    while(1){
        string a;
        cin >> a;
        if(a == "0") break;
        string b = a;
        reverse(a.begin(),a.end());
        
        if( a.compare(b) == 0 ) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}