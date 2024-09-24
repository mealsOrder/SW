#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

int main() {	
    string str;
    cin >> str;
    string res =str;
    reverse(str.begin(), str.end());
    
    if(res == str) cout << 1;
    else cout << 0;
    return 0;
}