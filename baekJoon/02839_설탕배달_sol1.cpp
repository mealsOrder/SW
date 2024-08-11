#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int INF = 987987987;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N;
    cin >> N;
    int cnt=0;
    int ans = INF;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if( (5*i+3*j) == N){
                ans = min(ans,i+j);
            }
        }
    }
    if(ans == INF) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}