#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    set<string>s;
    vector<string>ans;
    cin >>N>>M;
    string temp;

    while(N--){
        cin >> temp;
        s.insert(temp);
    }
    while(M--){
        cin >> temp;
        if(s.find(temp) != s.end()){
            ans.push_back(temp);
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(string& str:ans) cout << str << '\n'; 
    return 0;
}