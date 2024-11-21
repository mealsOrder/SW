#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
using ll = long long;
int L,P,V;
int t = 1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(1){
        ll ans = 0;
        cin >> L >> P >> V;

        if(L == 0 && P == 0 && V ==0)break;
        int use = V/P;
        int lef = V%P;
        if(L < lef) lef = L;
        ans = L * use + lef;
        cout << "Case " << t <<": " << ans << '\n';
        t++;
    }    

    return 0;
}