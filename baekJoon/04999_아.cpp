#include <iostream>
#include <string>

using namespace std;
int main(){
    string s1,s2;
    cin >> s1 >> s2;

    int cnt1=0,cnt2=0;

    for(int i=0;i<s1.length();i++){
        if(s1[i]=='a') cnt1++;
    }

    for(int i=0;i<s2.length();i++){
        if(s2[i]=='a') cnt2++;
    }

    if(cnt1>=cnt2||s1.length()==s2.length()) cout << "go";
    else cout << "no";
}