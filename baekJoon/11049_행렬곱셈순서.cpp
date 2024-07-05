#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<cmath>
const int MX = 501;
int DP[MX][MX]; // vector<vector<int>> v(MX); // 같은말
int matrix[MX][2]; // vector<pair<int,int>> matrix(MX); //같은 말
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    for(int i=1;i<=N;i++){
        cin >> matrix[i][0] >> matrix[i][1];
    }

    // 범위
    for(int i=1;i<N;i++){
        // 시작 행렬 번호
        for(int j=1;i+j<=N;j++){
            DP[j][i+j] = INT_MAX;
            // 중간 행렬
            for(int k=j;k<=i+j;k++){
                DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k+1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
            }
        }
    }

    cout << DP[1][N];

    return 0;
}