#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    while(N--){
        unordered_map<long long, int>m;
        int ti;
        cin >> ti;
        long long ans = -1;
        int mx = 0;

        for(int i=0;i<ti;i++){
            long long a;
            cin >> a;
            m[a]++;
            if(m[a] > mx){
                mx = m[a];
                ans = a;
            }
        }

        if( mx > ti/2) cout << ans << '\n';
        else cout << "SYJKGW\n";
    }

    return 0;
}