#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    cin.ignore(); // 입력 버퍼에 남아있는 개행 문자 제거
    vector<int>v;
    for(int i=0;i<N;i++){
        string str="";
        string token="";
        getline(cin,str);
        stringstream ss(str);
        int sum = 0;
        while(getline(ss,token,',')){
            sum += stoi(token);
        }
        v.push_back(sum);
    }
    for(int d:v) cout << d <<'\n';
    return 0;
}