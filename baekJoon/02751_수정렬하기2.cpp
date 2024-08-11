#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<int>v;
    int N;
    cin >> N;

    while(N--){
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    for(int elem:v)cout << elem << '\n';
    return 0;
}