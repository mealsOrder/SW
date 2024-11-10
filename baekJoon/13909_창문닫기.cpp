#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    int ans = 0;
    cin >> N;
    for(int i=1;i*i<=N;i++){
        ans++;
    }

    cout << ans;
    return 0;
}