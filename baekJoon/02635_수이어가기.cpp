#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int MX = 30001;
int first;
int second;
int total;
int dp[MX];
void dfs(int x, int pre,int cnt){
    int dis = pre - x;
    if(dis < 0){
        if(cnt>total){
            total = cnt;
            first = x;
            second = pre;
        }
        return;
    }
    else{
        dfs(dis,x,cnt+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;

    cin >> N;
    
    for(int i=1;i<=N;i++){
        dfs(i,N,1);
    }
    cout << total + 1 << '\n';
    //cout << first << '\n';
    //cout << second << '\n';
    //cout << "---\n";
    dp[0] = first;
    dp[1] = second;

    for(int i=2;i<=total;i++){
        dp[i] = dp[i-2] + dp[i-1];
    }

    for(int i=total;i>=0;i--){
        cout << dp[i] << ' ';
    }
    return 0;
}