#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int MX = 10001;
int d1[MX]; // 선택ㅇ
int d2[MX]; // 선택x

int arr[MX];
vector<int>adj[MX];

void dfs(int x,int par){
    d1[x] = arr[x];
    d2[x] = 0;

    for(int i=0;i<adj[x].size();i++){
        int nx = adj[x][i];

        if(nx == par)continue;

        dfs(nx,x);
        d1[x] +=d2[nx];
        d2[x] += max(d1[nx],d2[nx]);

    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for(int i=1;i<=N;i++)cin >> arr[i];

    for(int i=0;i<N-1;i++){
        int a,b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    for(int i=0;i<=N;i++){
        cout << d1[i] << ' ' << d2[i] << '\n';
    }

    return 0;
}