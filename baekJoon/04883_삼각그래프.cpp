#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
using ll = long long ;
const int MX = 100001;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=0;
    while(1){

        int N;
        cin >> N;
        T++;
        if(N == 0) break;
        ll dp[N+1][4]={0,} ;
        int a[N+1][4]={0, } ;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=3;j++){
                cin >> a[i][j];
            }
        }
        dp[1][2] = a[1][2];
        dp[1][3] = a[1][2] + a[1][3];
        
        dp[2][1] = a[1][2] + a[2][1]; 
        dp[2][2] = min({dp[2][1],dp[1][2],dp[1][3]}) + a[2][2];
        dp[2][3] = min({dp[1][2],dp[1][3],dp[2][2]}) + a[2][3];
        if( N == 2){
            cout << T << '.' << ' ' <<  dp[N][2] << '\n';
            continue;
        }
        for(int i=3;i<=N;i++){
            for(int j=1;j<=3;j++){
                if(j==1){
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j+1]) + a[i][j];
                }
                else if( j == 2){
                    dp[i][j] = min( min(dp[i-1][j-1],dp[i][j-1]), min(dp[i-1][j], dp[i-1][j+1])) + a[i][j];
                }
                else{
                    dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}) + a[i][j];
                }
            }
        }
        
        cout << T << '.' << ' ' <<  dp[N][2] << '\n';
    }

    return 0;
}