#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;
int N;

vector<pair<int,int>>v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;

    for(int i=0;i<N;i++){
        int sm,sd,em,ed;
        cin >> sm >> sd >> em >> ed;
        v.push_back({sm*100+sd,em*100+ed});
    }

    int t = 301;
    int ans = 0;
    while(t<1201){
        int nxt = t;
        for(int i=0;i<N;i++){
            if(v[i].first <=t && v[i].second > nxt)nxt = v[i].second;
        }
        if(nxt == t){
            cout << 0;
            return 0;
        }
        ans++;
        t = nxt;
    }

    cout << ans << '\n';
    return 0;
}