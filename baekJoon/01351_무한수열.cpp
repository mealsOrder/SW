#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;

ll n,p,q;
map<ll,ll>a;

ll func(ll x){
    if(a[x] != 0){
        return a[x];
    }
    if(x == 0){
        return a[x]=1;
    }
    return a[x] = func(x/p) + func(x/q);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p >> q;

    cout << func(n) << '\n';
    return 0;
}
