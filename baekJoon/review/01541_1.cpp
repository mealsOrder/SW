#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string in;
    cin >> in;
    int res = 0;
    string tem = "";
    bool flag = false;
    for(int i=0;i<=in.length();i++){
        if(in[i] == '-' || in[i]=='+' || in[i] == '\0'){
            if(flag) res -= stoi(tem);
            else res += stoi(tem);
            tem="";
            if(in[i] == '-') flag = true; 
        }
        else{
            tem += in[i];
        }
    }
    cout << res;
    return 0;
}