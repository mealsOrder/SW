#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 11;
int coin[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    int cnt = 0;
    cin >>N>>K;
    for(int i=0;i<10;i++){
        cin >> coin[i];
    }
    for(int i=N-1;i>=0;i--){
        cnt += K/coin[i]; 
        K = K%coin[i];
    }
    cout << cnt;
    return  0;
}