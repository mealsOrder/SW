#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

string str;
int ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> str;
    stack<char>s;

    for(int i=0;i<str.size();i++){
        if(str[i] == '(')s.push(str[i]);
        else{
            if(str[i-1] == '('){
                s.pop();
                ans+=s.size();
            }
            else{
                s.pop();
                ans++;
            }
        }
    }
    cout << ans;

	return 0;
}