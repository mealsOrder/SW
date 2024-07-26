#include<iostream>
#include<string>
using namespace std;
/**
 * p199
 * 빈칸을 포함하는 문자열을 입력 받고, 한 문자씩 왼쪽으로
 * 회전하도록 문자열을 변경하고 출력
 */
int main(){
    string s;

    cout << "아래에 문자열을 입력하세요. 빈칸ㅇ";
    getline(cin,s,'\n');
    int len = s.length();

    for(int i=0;i<len;i++){
        string first = s.substr(0,1);
        string sub = s.substr(1,len-1);
        s = sub+first;
        cout << s << '\n';
    }
    return 0;
}