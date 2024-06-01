#include<iostream>
#include<string>
using namespace std;

int recursion(const string &s, int l, int r, int &count){
    count++; // 재귀 호출 횟수를 증가시킵니다.
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, count);
}

int isPalindrome(const string &s, int &count){
    return recursion(s, 0, s.size()-1, count);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while(T--){
        string S;
        cin >> S;
        int count = 0;
        int result = isPalindrome(S, count);
        cout << result << ' ' << count << '\n';
    }

    return 0;
}