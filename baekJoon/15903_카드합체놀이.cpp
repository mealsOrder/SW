#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,M;
long long ans;
vector<int>v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<M;i++){
        int hap = v[0] + v[1];
        v[0] = hap;
        v[1] = hap;
        sort(v.begin(),v.end());
    }

    for(int i=0;i<N;i++){
        ans += v[i];
    }
    cout << ans << '\n';
    return 0;
}