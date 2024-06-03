#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >>N>>M;
    vector<string>arr(N),brr(M),ans;
    for(string &s:arr) cin>>s;
    for(string &s:brr) cin>>s;

    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());

    set_intersection(arr.begin(),arr.end(),brr.begin(),brr.end(),back_inserter(ans));
    
    cout << ans.size() << '\n';
    for(string &s:ans) cout << s << '\n';
    
    return 0;
}