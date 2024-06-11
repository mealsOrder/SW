#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int P,Q,A,B,C,D;
        cin >> P>>Q>>A>>B>>C>>D;
        int coin = (Q/C)*D;
        P+= (coin/B)*A;
        coin = coin%B;

        int x = (P-coin)/(A+B);
        int ans = max( min(coin+(B*x),P-(A*x)), min(coin+(B*(x+1)),P-(A*(x+1))));
        cout << ans << '\n';
    }
	return 0;
}
