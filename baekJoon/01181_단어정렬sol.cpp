#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

const int MAX = 20001;
vector<pair<int,string>>s;

int main() {
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        string a;
        cin >> a;
        int len = a.length();
        s.push_back({len,a});
    }
    
    sort(s.begin(),s.end());
    //cout << "정렬"<< endl;
    for(int i=0;i<N;i++){
        // string 비교 compare 같으면 0, 다르면 -1 반환
        if( s[i+1].second.compare(s[i].second) ){
            cout << s[i].second << endl;    
        }
    }
    return 0;
}