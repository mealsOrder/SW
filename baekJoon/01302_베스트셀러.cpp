#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
string compare(string a, string b){
    if(a<b) return a;
    return b;
}
map<string,int>m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int mx = 0;
    string ans="";
    for(int i=0;i<N;i++){
        string name;
        cin >> name;
        m[name]++;
        if(m[name] > mx){
            mx = m[name];
            ans = name;
        }
        else if(m[name] == mx){
            ans = compare(name,ans);
        }
    }

    cout << ans;
    return 0;
}