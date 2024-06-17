#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
const int MX = 100001;
int arr[MX];
long long ans = -999999999;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,K;
    cin >> N>>K;
    for(int i=0;i<N;i++) cin >> arr[i];

    long long  res = 0;
    for(int i=0;i<K;i++){
        res += arr[i];
    }
    ans = max(ans, res);
    for(int i=K;i<N;i++){
        res = res - arr[i-K] + arr[i];
        ans = max(ans,res);
    }
    cout << ans << '\n';
    return 0;
}