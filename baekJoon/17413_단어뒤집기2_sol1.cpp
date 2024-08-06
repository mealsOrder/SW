#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int N;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string str;         // 입력 받는 문자 
    getline(cin,str);   // 한줄로 입력
    string ans="";      // 정답 문자열
    string tmp="";      // 임시 저장 문자열
    bool flag = false;  // <> 안의 문자열인지 체크하기 위한 플레그
    // 문자열 순회
    for(int i=0;i<str.size();i++){
        // 문자가 < 이면
        if(str[i] == '<'){
            // 지금까지 임시 저장된 문자를 거꾸로 만든다
            reverse(tmp.begin(),tmp.end());
            ans+=tmp;    // 거꾸로 만든 문자열을 정답에 누적해줌
            tmp="";      // 임시 문자열 초기화
            flag = true; // 꺽쇠 안이라는것을 표시
        }
        // 문자가 > 이면
        else if(str[i] == '>'){
            ans += str[i]; // 현재 문자 > 를 정답에 추가
            flag = false;  // 꺽쇠가 끝났다는 것을 표시
            continue;      // 다음 문자로 넘어감
        }
        // 꺽쇠 안쪽이라면 문자열을 그대로 누적
        if(flag == true) ans += str[i];
        // 꺽쇠 바깥쪽일때
        else{
            // 문자가 공백이면
            if(str[i] == ' '){
                // 또 임시 저장된 문자를 거꾸로 만들고
                reverse(tmp.begin(),tmp.end());
                ans+=tmp;       // 정답에 누적해준다
                ans += ' ';     // 정답에 공백을 추가해주고
                tmp = "";       // 임시 문자열 초기화
            } else tmp += str[i];// 꺽쇠바깥쪽이고 공백도 아니면 임시 문자열에 누적
        }
    }
    // 순회를 다 하고도 남은 문자열 처리
    // 임시 저장한것이 남아 있다면
    if(tmp!=""){
        // 임시 저장된 문자열을 거꾸로 만들고
        reverse(tmp.begin(),tmp.end());
        ans+=tmp;   // 정답에 누적
    }
    cout << ans << '\n'; // 정답 출력!
    return 0;
}
