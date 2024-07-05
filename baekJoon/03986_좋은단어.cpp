#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<climits>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    int ans = 0;
    while(N--){
        stack<char>s;
        string str="";
        cin >> str;
        s.push(str[0]);
        for(int i=1;i<str.size();i++){
            char data = str[i];
            
            if(!s.empty() && s.top() == data) s.pop();
            else s.push(data);
        }
        if(s.size() == 0) ans ++;

    }
    cout << ans << '\n';
    return 0;
}