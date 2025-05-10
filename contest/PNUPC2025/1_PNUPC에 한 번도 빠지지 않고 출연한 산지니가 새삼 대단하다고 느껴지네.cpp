#include <iostream>
using namespace std;

bool alpha[26];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string name, str;
    cin >> name >> str;

    for(char c : name){
        alpha[c - 'a'] = true;
    }

    for(char c : str){
        if(!alpha[c - 'a']) cout << c;
    }

    cout << '\n';
    return 0;
}
