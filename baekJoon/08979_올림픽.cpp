#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
const int MX=1001;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N,K;
    cin >> N >> K;
    vector< pair< pair<int,int> , pair<int,int> > >v(N); // 금, 은, 동, 국가 코드

    for(int i=0;i<N;i++){
        int a,b,c,d;
        cin >> a >> b >> c >>d;
        v.push_back({{b,c},{d,a}});
        
    }
    sort(v.begin(),v.end(),greater<>());
    int ans = 0;

    int G=-1,S=-1,B=-1;
    for(int i=0;i<N;i++){
        auto cur = v[i];
        if(G != cur.first.first || S != cur.first.second || B != cur.second.first){
            ans = i+1;
        }
        if(cur.second.second == K) break;
        G = cur.first.first;
        S = cur.first.second;
        B = cur.second.first;        
    }
    cout << ans << '\n';
    return 0;
}
