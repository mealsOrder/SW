#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 42;
vector<pair<int,int>>v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    v.push_back({1,0});
    v.push_back({0,1});
    for(int i=2;i<=40;i++){
        v.push_back({v[i-1].first+v[i-2].first,v[i-1].second+v[i-2].second });
    }
    
    while(N--){
        int a;
        cin >> a;
        cout << v[a].first << " " << v[a].second<<'\n';
    }


    return 0;
}