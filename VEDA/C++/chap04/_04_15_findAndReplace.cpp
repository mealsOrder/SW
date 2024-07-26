#include<iostream>
#include<string>
using namespace std;
/**
 * [p201]
 * &키가 입력될 때까지 여러줄의 영문 문자열을 받고
 * 찾는 문자열과 대치할 문자열을 입력받아 변경해라
 */
int main(){
    string s;

    cout << "아래에 문자열을 입력하세요. 입력끝&";
    getline(cin,s,'&'); // &나올때까지 문자열 입력 받아라
    cin.ignore();

    string f,r; // 검색, 대체 문자열
    cout << "find : ";
    getline(cin,f,'\n');
    cout << "replace : ";
    getline(cin,r,'\n');

    int st = 0;

    while(true){
        int idx = s.find(f,st); // s에서 f를 찾는데 0부터 시작~
        if(idx == -1){
            break;
        }
        s.replace(idx,f.length(),r);// s에서 idx부터 f의 길이만큼,r문자열로 대체
        st = idx+r.length();        // 시작지점을 idx에서 대체할 문자열의 길이 만큼으로 갱신
    }
    cout << s << '\n';
    return 0;
}