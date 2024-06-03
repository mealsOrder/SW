#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * 사용자로 부터 문자열의 개수를 입력 받은 후,
 * 그 개수 만큼 문자열을 입력받아 벡터에 저장.
 * 그런다음 벡터의 모든 문자열을 출력
 * for 문을 다음과 같이 사용하면 깔끔하게 쓸수있음!
*/
int main(){
    int N;
    cin >>N;

    vector<string>arr(N); // string 벡터 배열 생성
    for(string&s : arr) cin >> s;

    for(string&s : arr) cout << s << '\n';

    return 0;
}