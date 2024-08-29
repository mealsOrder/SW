#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll S,total=0,ans=0;
    cin >> S;


    while(total < S){
        total = (ans*(ans+1)) / 2;
        if(total > S)break;
        ans++;
    }
    cout << ans-1 << '\n';
    return 0;
}