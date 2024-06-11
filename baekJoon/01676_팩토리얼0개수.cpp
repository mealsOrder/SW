#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
const int MX = 501;
int dp[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >>N;
    int cnt = 0;
    for(int i=5;i<=N;i+=5){
        int num = i;
        while(num%5 == 0){
            cnt++;
            num /= 5;
        }
    }    
    cout << cnt << '\n';
	return 0;
}