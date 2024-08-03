#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int N;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string str;
    getline(cin,str);
    string ans="";
    string tmp="";
    bool flag = false;
    for(int i=0;i<str.size();i++){
        if(str[i] == '<'){
            reverse(tmp.begin(),tmp.end());
            ans+=tmp;
            tmp="";
            flag = true;
        }
        else if(str[i] == '>'){
            ans += str[i];
            flag = false;
            continue;
        }
        if(flag == true) ans += str[i];
        else{
            if(str[i] == ' '){
                reverse(tmp.begin(),tmp.end());
                ans+=tmp;   
                ans += ' ';
                tmp = "";
            } else tmp += str[i];
        }
    }
    if(tmp!=""){
        reverse(tmp.begin(),tmp.end());
        ans+=tmp;
    }
    cout << ans << '\n';
    return 0;
}
