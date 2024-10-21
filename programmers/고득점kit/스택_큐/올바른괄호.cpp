#include<string>
#include <iostream>
#include<stack>
using namespace std;

bool solution(string s)
{
    bool ans = false;
    stack<char>st;

    if( s[0] == ')'){
        return ans;
    }
    for(char a:s){
        
        if (!st.empty() && a == ')'){
            st.pop();
        }
        else{
            st.push(a);
        }
    }

    if(st.size() == 0) ans = true;

    return ans;
}

int main(){
    return 0;
}