#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
const int MX = 11;
const int INF = INT_MAX;
int N;
int W[MX][MX];
bool vis[MX];
int ans = INF;

void DFS(int s,int now,int sum,int cnt){
    if(cnt == N && W[now][s] != 0){
        ans = min(ans,sum+W[now][s]);
        return;
    }

    for(int i=0;i<N;i++){
        if(!vis[i] && W[now][i] !=0){
            vis[i]=true;
            DFS(s,i,sum+W[now][i],cnt+1);
            vis[i]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> W[i][j];

    for (int i = 0; i < N; i++) {
        vis[i] = true;
        DFS(i, i, 0, 1);
        vis[i] = false;
    }

    cout << ans << '\n';
    return 0;
}