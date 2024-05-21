#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 100001;
vector<pair<int,int>>v;
bool cmp(pair<int,int>x,pair<int,int>y){
    if(y.second == x.second){
        return x.first < y.first;
    }
    else{
        return x.second <y.second;
    }
}

int main() {
    
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >>b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<N;i++){
        cout << v[i].first << " " <<v[i].second << '\n';
    }

    return 0;
}