#include<iostream>

using namespace std;
// 문자열 배열에서 매개 변수로 주어진 
//인덱스의 원소 공간에 대한 참조를 리턴하는 find() 함수 작성

char &find(char s[], int idx)
{
    return s[idx];
}

// 전통적인 방법으로 1차원 배열을 매개변수로 받는법!
char& find2(char *s, int idx)
{
    return s[idx];
}
// 전통적인 방법으로 2차원 배열을 매개변수로 받는법!
// ex) int a[2][3] = { .. }
char& find3(char (*s)[3], int i,int j)
{
    return s[i][j];
}


int main()
{
    char name[] = "MIKE";
    cout << name << '\n';
    char k[2][3] = { 'A','B','C','D','E','F'};
    find(name,0) = 'S';
    cout << name << '\n';

    char &ref = find(name,2);
    ref = 't';
    cout << name << '\n';

    find2(name,0) = 'T';
    cout << name << '\n';

    // 2차원 배열을 매개변수로 넘겨서 참조 리턴으로 값을 바꾸는 방법!
    find3(k,1,1) = 'G';
    for(int i = 0;i<2;i++){
        for(int j=0;j<3;j++){
            cout << k[i][j] << " " ;
        }
        cout << '\n';
    }
}