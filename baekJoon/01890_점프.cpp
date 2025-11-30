#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
using namespace std;

const int MX = 101;
int m[MX][MX];
int N;
int dx[] = {0,1};
int dy[] = {1,0};
long long dp[MX][MX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> m[i][j];
        }
    }

    dp[0][0] = 1;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i == N-1 && j ==N-1)continue;
            int jump = m[i][j];
            if(i+jump < N) dp[i+jump][j] += dp[i][j];
            if(j+jump < N) dp[i][j+jump] += dp[i][j];
        }
    }

    cout << dp[N-1][N-1] << '\n';

    return 0;
}
