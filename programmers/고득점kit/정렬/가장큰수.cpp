#include <string>
#include <vector>
#include<algorithm>
using namespace std;

//solve time : 21 min ...

bool compare(string a, string b){
    return a+b>b+a;
}

string solution(vector<int> n) {
    string ans="";
    vector<string>v;

    for(int num: n){
        v.push_back(to_string(num));
    }

    sort(v.begin(),v.end(),compare);

    
    for(string num:v){
        ans+=num;
    }
    // 여기가 핵심 반환형이 string 이므로 return 0 하면 오류남... ㅇㅋ
    if(ans[0] == '0' ) return "0";
    return ans;
}

int main(){
    return 0;
}