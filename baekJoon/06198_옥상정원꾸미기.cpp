#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<climits>
using namespace std;
typedef long long ll;
const int MX = 80001;
stack<int>s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll cnt=0;
    int N;
    cin >>N;
    while(N--){
        int h;
        cin >> h;

        if(s.empty()) s.push(h);
        while(!s.empty() && s.top() <= h)s.pop();
        cnt += s.size();
        s.push(h);
    }

    cout << cnt << '\n';
    return 0;
}