#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

stack<char>s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str="";
    cin >> str;

    for(char c:str){
        if(c>='A' && c<='Z')cout << c;
        else{
            if(c == '(') s.push(c);
            else if(c == ')'){
                while(!s.empty()&&s.top()!='('){
                    cout << s.top();
                    s.pop();
                }
                s.pop();
            }
            else if(c=='*'||c=='/'){
                while(!s.empty()&& (s.top()=='*'||s.top()=='/')){
                    cout << s.top();
                    s.pop();
                }
                s.push(c);
            }
            else if(c=='+'||c=='-'){
                while(!s.empty()&&s.top()!='('){
                    cout << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    return 0;
}