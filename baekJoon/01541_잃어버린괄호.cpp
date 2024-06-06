#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int main(){
	string in;
    cin >> in;

    int res = 0;
    string tem = "";
    bool flag = false;
    for(int i=0;i<=in.length();i++){
        // \0 : null 문자 문자열의 끝을 표시하는데 주로 사용
        if(in[i] == '-' ||in[i] == '+' ||in[i] == '\0'){
            if(flag){
                res -= stoi(tem);
            }
            else{
                res += stoi(tem);
            }
            tem = "";
            if(in[i] == '-'){
                flag = true;
            }
        }
        else{
            tem+=in[i];
        }
    }
    cout << res;
    return 0;
}
