#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str;
    string tmp="";
    string ans="";
    bool flag = false;
    getline(cin,str);

    for(char i : str){
        if( i == '<'){
            reverse(tmp.begin(),tmp.end());
            ans+=tmp;
            tmp="";
            flag = true;
        }
        else if(i == '>'){
            ans += i;
            flag = false;
            continue;
        }
        if(flag == true) ans+=i;
        else{
            if(i == ' '){
                reverse(tmp.begin(),tmp.end());
                ans+=tmp;
                ans+=' ';
                tmp="";
            }else tmp+=i;
        }
    }
    if(tmp!=""){
        reverse(tmp.begin(),tmp.end());
        ans+=tmp;
    }
    cout << ans << '\n';
    return 0;
}