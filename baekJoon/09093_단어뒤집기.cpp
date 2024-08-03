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
    cin.ignore(); // 이거 안해서 애먹음
                  // 이전 입력 후 남아 있는 개행 문자 제거
    while(N--){
        string str;
        stack<char>s;
        getline(cin,str);
        str += ' ';     // 문자열 끝에 공백 추가(마지막 문자 처리용)
        // 문자열 순회
        for(char i:str){
            // 공백을 만나면
            if(i == ' '){
                // 스택이 비지 않을때 까지 스택 상단 문자 출력
                while(!s.empty()){
                    cout << s.top();
                    s.pop(); // 최상단 문자 제거
                }
                cout << ' '; // 공백 출력, 공백을 만나기만 하지 처리를 하지 않으므로 추가해줘야함
            }
            // 공백이 아닐경우 스택에 추가
            else{
                s.push(i);
            }
        }
        // 테스트 케이스 결과 출력후 줄바꿈 위해서
        cout << '\n';
    }

    return 0;
}
