#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
#include<climits>
using namespace std;

const int MX = 10001;
int in[MX];
vector<int>adj[MX];
int cost[MX];
int ans[MX];
queue<int>q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N;
    cin >> N;

    for(int i=1;i<=N;i++){
        int cnt;
        cin >> cost[i] >> cnt;

        while(cnt--){
            int node;
            cin >> node;
            // i번 작업 이전에 node
            adj[i].push_back(node);
            in[i]++;
        }
    }

    for(int i=1;i<=N;i++){
        if(in[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0;i<adj[cur].size();i++){
            int nx = adj[cur][i];
            in[nx]--;
            if(in[nx] == 0){
                q.push(nx);
                ans[nx] = max(ans[nx], ans[cur] + cost[cur]);
            }
        }
    }

    for(int i=1;i<=N;i++){
        cout << ans[i] + cost[i] << " ";
    }
    cout << '\n';
    cout << ans[0];
    return 0;
}