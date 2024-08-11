#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<int>v;
    int N=3;
    while(N--){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());

    cout << v[1] << '\n';
    return 0;
}