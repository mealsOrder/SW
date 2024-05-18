#include <iostream>
#include <string>

using namespace std;

int main() {

    string str1 = "ABCDE";
    str1.erase(str1.begin());                           // ù ���� ����
    cout << str1 << endl;                               // BCDE

    string str2 = "ABCDE";
    str2.erase(str2.end()-1);                           // ������ ���� ����
    cout << str2 << endl;                               // ABCD

    // �Ű������� �ݺ��ڷ� ����

    string str3 = "ABCDE";
    str3.erase(str3.begin() + 1);                       // 1�� index ���� 
    cout << str3 << endl;                               // ACDE

    string str4 = "ABCDE";
    str4.erase(str4.begin() + 1, str4.begin() + 3);     // 1�� index���� 2�� index���� ����
    cout << str4 << endl;                               // ADE

    // �Ű������� ���ڷ� ����

    string str5 = "ABCDE";
    str5.erase(2,2);                                    // 2�� index���� 2�� ����
    cout << str5 << endl;                               //ABE

    string str6 = "ABCDE";
    str6.erase(2);                                      // 2�� index���� ������ index���� ���� ����
    cout << str6 << endl;                               // AB

    return 0;
}