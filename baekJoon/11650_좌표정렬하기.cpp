#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int,int>>v;

    for(int i=0;i<N;i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    
    sort(v.begin(),v.end());

    for(int i=0;i<N;i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
    return 0;
}