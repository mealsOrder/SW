#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;

const int MAX = 20001;
set<string>k;
vector<pair<string,int>>s;
// first : 단어, second : 길이
bool cmp(pair<string,int>x,pair<string,int>y){
    if(x.second == y.second){
        return x.first<y.first;
    }
    return x.second<y.second;
}

int main() {
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        string a;
        cin >> a;
        int len = a.length();
        s.push_back({a,len});
    }

    sort(s.begin(),s.end(),cmp);
    //cout << "정렬"<< endl;
    for(int i=0;i<N;i++){
        if(s[i+1].first == s[i].first){
            continue;
        }
        cout << s[i].first << endl;
    }
    return 0;
}