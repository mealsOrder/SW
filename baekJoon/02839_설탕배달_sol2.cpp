#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N;
    cin >> N;
    int ans = 0;
    ans=N/5;
    for(;ans>=0;ans--){
        if((N-5*ans)%3 == 0){
            ans+=(N-5*ans)/3;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}