#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>p;
vector<int>m;
int ans;
void tie(vector<int>v){
    while( 1 < v.size()){
        ans += *(v.end()-1) * *(v.end()-2);
        v.pop_back();
        v.pop_back();
    }
    if(v.size()){
        ans += v[0];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        if(a == 1) ans++;
        else if(a>0) p.push_back(a);
        else m.push_back(a);
    }
    
    sort(p.begin(),p.end());
    sort(m.begin(),m.end(),greater<>());
    tie(p);
    tie(m);
    cout << ans << '\n';
    return 0;
}