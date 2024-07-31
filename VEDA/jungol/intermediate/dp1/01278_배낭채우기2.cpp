#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 1005; // 번호는 1000 까지 무게는 10000 까지...
int dp[MX][10001];   // 보석 무게 범위 조심!!!
int W[MX];
int P[MX];

int main(){
    int N,L;    
    cin >> N >> L;

    for(int i=1;i<=N;i++){
        cin >>W[i] >> P[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=L;j++){
            if(j < W[i]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-W[i]]+P[i]);
            }
        }
    }

    cout << dp[N][L] << '\n';
	return 0;
}