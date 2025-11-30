#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MX = 501;
/**
 * @brief 간단한 냅색문제
 * 
 */
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int N,P,B;
        cin >> N >> P >> B;
        int a[MX] = {0,};
        int dp[MX][61] = {0,};
        for(int i=1;i<=N;i++)cin >> a[i];

        for(int i=1;i<=N;i++){
            for(int j=0;j<=60;j++){
                if(j>a[i]){
                    dp[i][j] = P;
                }
                else{
                    dp[i][j] = B*j;
                }
            }
        }

        int sum[MX] = {0,};
        for(int i=0;i<=60;i++){

            for(int j=0;j<=N;j++){
                
                sum[i] += dp[j][i];
            }
        }

        int ans = 0;
        for(int i=0;i<=60;i++){
            ans = max(ans,sum[i]);
        }
        cout << '#' << t << ' ' <<  ans << '\n';
    }

    return 0;
}