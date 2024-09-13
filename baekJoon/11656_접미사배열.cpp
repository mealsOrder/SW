#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;
stack<char>s;
vector<string>v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str,ans="",res="";
    cin >> str;

    for(char c : str){
        s.push(c);
    }
    while(!s.empty()){
        char cur = s.top();
        reverse(ans.begin(),ans.end());
        s.pop();
        ans+=cur;
        reverse(ans.begin(),ans.end());
        v.push_back(ans);
    }
    
    sort(v.begin(),v.end());
    for(string d : v){
        cout << d << '\n';
    }

    return 0;
}