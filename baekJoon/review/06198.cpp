#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    stack<int>s;
    ll ans = 0;
    for(int i=0;i<N;i++){
        int h;
        cin >> h;

        if(s.empty()) s.push(h);
        while(!s.empty() && s.top() <= h)s.pop();
        ans += s.size();
        s.push(h);
    }
    cout << ans << '\n';
    return 0;
}
