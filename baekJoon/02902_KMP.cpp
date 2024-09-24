#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string str;
    cin >> str;
    vector<char>v;
    for(char c :str){
        if(c >= 'A' && c <= 'Z'){
            v.push_back(c);
        }
    }
    for(char c :v){
        cout << c;
    }
    return 0;
}