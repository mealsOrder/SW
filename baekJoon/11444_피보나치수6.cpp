#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;

/**
 * 일단 N의 범위가 너무나도 크다 10^18
 * f0 = 0
 * f1 = 1
 * f2 = 1
 * fn = fn-1+fn-2;
 * 일단 일반적인 방법으로는 long long, dp ㄴㄴ... 
 * 분할 정복을 생각해서 피보나치 수를 구해야 할것 같음 ...
 * 함수로 만들어서? string 으로 처리 해볼까? ㄴㄴ ...
 * 행렬곱을 이용한 방법으로 ㅇㅇ!
 * 
 * 피보나치 수를 행렬로 나타내면 아래와 같음
 * |fn+2 |   | 1 1 | | fn+1|
 * |fn+1 | = | 1 0 | |  fn |
 * 따라서, 위 식을 정리하면 아래와 같이 나타낼 수 있음
 * |fn+1 fn   |   | 1 1 | ^ n
 * |fn   fn-1 | = | 1 0 |
 */

const ll MOD = 1000000007;

// 2*2 행렬의 곱셈 함수
vector<vector<ll>> matrixMul(vector<vector<ll>>a,vector<vector<ll>>b){
    vector<vector<ll>> res(2,vector<ll>(2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                res[i][j] = (res[i][j]+a[i][k]*b[k][j])%MOD;
            }
        }
    }
    return res;
}

// 행렬의 거듭제곱 함수
vector<vector<ll>> matrixPow(vector<vector<ll>> a, ll n){
    if(n==1)return a;
    if(n%2==0){
        vector<vector<ll>> even = matrixPow(a,n/2);
        return matrixMul(even,even);
    } else{
        vector<vector<ll>> odd = matrixPow(a,n-1);
        return matrixMul(a,odd);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;

    if(n<=1){
        cout << n << '\n';
        return 0;
    }
    // 초기 행렬 설정
    vector<vector<ll>> init = {{1,1},{1,0}};

    // 행렬 거듭제곱을 통해 n번째 피보나치수 계산
    vector<vector<ll>> res = matrixPow(init,n-1);

    // 결과 출력
    cout << res[0][0] << '\n';
    return 0;
}