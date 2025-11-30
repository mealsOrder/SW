#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
using ll = long long;
const int MX = 100005;

vector<int>adj[MX];
bool vis[MX];
int arr[MX];
ll dp[MX];
void dfs(int x){
    if(vis[x])return;
    vis[x] = true;
    dp[x] = arr[x];
    ll mxChild = 0;
    for(int i=0;i<adj[x].size();i++){
        int nx = adj[x][i];

        if(vis[nx]) continue;
        dfs(nx);
        dp[x] = max(dp[x]+dp[nx],dp[x]);
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    for(int i=1;i<N;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<N;i++)cin >> arr[i];

    dfs(0);
    cout << dp[0] << '\n';


    return 0;
}