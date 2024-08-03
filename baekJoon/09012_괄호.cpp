#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    // n번 반복
    while(N--){
        // 문자열, 스택, 플래그 매번 시작할때 초기화
        string str;
        stack<char>s;
        bool flag = true;
        // 문자열 입력
        cin >> str;

        // 입력받은 문자열 순회
        for(char i : str){
            // 문자가 ( 이면 스택에 넣는다 
            if(i == '(') s.push(i);
            // 스택이 비어있고 문자가 ) 이면 짝이 맞지 않으므로 플래그 false를준다
            if(s.empty() && i == ')'){
                flag = false;
            }
            // 스택이 비어 있지 않고 문자가 ) 이면 
            // 스택에 들어 있는 (과 짝을 이루므로 ( 를 pop 해준다
            if(!s.empty() &&i == ')') s.pop();
        }
        // 스택이 비어있지 않거나 플래그가 false 이면 NO
        if(!s.empty() || !flag) cout << "NO\n";
        // 스택이 비어있으면 짝이 다 맞으므로 YES
        else cout << "YES\n";
    }

    return 0;
}
