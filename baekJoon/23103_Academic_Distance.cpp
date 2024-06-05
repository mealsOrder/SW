#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<cmath>
#include<cstring>
using namespace std;
const int MX = 101;
vector<pair<int,int>>v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >>N;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a>>b;
        v.push_back({a,b});
    }
    int res = 0;
    for(int i=1;i<N;i++){
        res += abs(v[i].first - v[i-1].first) + abs(v[i].second - v[i-1].second);
    }
    cout << res;
    return 0;
}