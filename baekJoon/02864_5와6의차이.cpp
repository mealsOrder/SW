#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string c,d;
    cin >> c >> d;
    for(char &s:c){
        if (s == '5') s='6';
    }

    for(char &s:d){
        if (s == '5') s='6';
    }
    int ansMx = stoi(c) + stoi(d);

    for(char &s:c){
        if (s == '6') s='5';
    }
    for(char &s:d){
        if (s == '6') s='5';
    }
    int ansMn = stoi(c) + stoi(d);
    
    cout << ansMn << " " << ansMx;
    
    return 0;
}