#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        int N;
        cin >> N;
        if(N==0)break;
        stack<pair<ll,ll>>s;
        ll ans = 0;
        for(int i=0;i<N;i++){
            int h;
            cin >> h;
            int idx = i;
            while(!s.empty() && s.top().first >= h ){
                ans = max(ans, 1LL*(i-s.top().second) * s.top().first);
                idx = s.top().second;
                s.pop();
            }
            s.push({h,idx});
        }
        while(!s.empty()){
            ans = max(ans,1LL*(N-s.top().second)*s.top().first);
            s.pop();
        }
        cout << ans << '\n';
    }

    return 0;
}