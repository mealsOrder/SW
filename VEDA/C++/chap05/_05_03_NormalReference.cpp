#include<iostream>
#include<string>
using namespace std;

int main()
{
    cout << "i" << '\t' << "n" << '\t' << "refn" << '\n';
    int i = 1;
    int n = 2;
    int &refn = n; // 참조 변수 refn 선언. refn은 n에 대한 별명
    n = 4;
    n=4;
    refn++; // refn=5 n =5;
    cout << i << '\t' << n << '\t' << refn << '\n';

    refn = i; // refn = 1, n = 1;
    refn++;   // refn = 2, n = 2;

    cout << i << '\t' << n << '\t' << refn << '\n';

    int *p = &refn; // p 는 refn의 주소를 가짐. p는 n의 주소
    *p = 20; // refn=20,n=20
    cout << i << '\t' << n << '\t' << refn << '\n';
    return 0;
}