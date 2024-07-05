#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<cmath>
#include<unordered_map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,Ti;
    cin >> N;

    for(int i=0;i<N;i++){
        unordered_map<long long,int>m;
        long long ans = -1;
        long long mx = 0;
        cin >> Ti;
        for(int j=0;j<Ti;j++){
            long long a;
            cin >> a;
            m[a]++;
            if(m[a] > mx){
                mx = m[a];
                ans = a;
            }
        }
        if( mx > Ti/2)cout << ans << '\n';
        else cout << "SYJKGW\n";

    }
    return 0;
}