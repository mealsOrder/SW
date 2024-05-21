#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

const int MAX = 100001;
// ���� �̸�
vector<pair<int,string>>v;

// <���� <����, �̸�>> : �̷��� �ؼ� ���� ���� stable sort�� ���� ��...
// pair<int,pair<int,string>>

bool cmp(pair<int,string>x,pair<int,string>y){
    return x.first <y.first;
}

int main() {
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int a;
        string b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    stable_sort(v.begin(),v.end(),cmp);

    for(int i=0;i<N;i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }

    return 0;
}