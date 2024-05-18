#include <iostream>
#include <string>

using namespace std;

int main() {

    string str1 = "ABCDE";
    str1.erase(str1.begin());                           // 첫 글자 삭제
    cout << str1 << endl;                               // BCDE

    string str2 = "ABCDE";
    str2.erase(str2.end()-1);                           // 마지막 글자 삭제
    cout << str2 << endl;                               // ABCD

    // 매개변수를 반복자로 선언

    string str3 = "ABCDE";
    str3.erase(str3.begin() + 1);                       // 1번 index 삭제 
    cout << str3 << endl;                               // ACDE

    string str4 = "ABCDE";
    str4.erase(str4.begin() + 1, str4.begin() + 3);     // 1번 index부터 2번 index까지 삭제
    cout << str4 << endl;                               // ADE

    // 매개변수를 숫자로 선언

    string str5 = "ABCDE";
    str5.erase(2,2);                                    // 2번 index부터 2개 삭제
    cout << str5 << endl;                               //ABE

    string str6 = "ABCDE";
    str6.erase(2);                                      // 2번 index부터 마지막 index까지 전부 삭제
    cout << str6 << endl;                               // AB

    return 0;
}