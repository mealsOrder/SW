#include<iostream>
using namespace std;
int main() {
    
    while(1){
        string a;
        bool flag = true;
        cin >> a;
        if(a == "0") break;
        for(int i=0;i<a.length()/2;i++){
            if(a[i] != a[a.length()-1-i]){
                flag = false;
                break;
            }
        }

        if( flag ) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}