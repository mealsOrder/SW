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
    //cout << "����"<< endl;
    for(int i=0;i<N;i++){
        // string �� compare ������ 0, �ٸ��� -1 ��ȯ
        if( s[i+1].second.compare(s[i].second) ){
            cout << s[i].second << endl;    
        }
    }
    return 0;
}