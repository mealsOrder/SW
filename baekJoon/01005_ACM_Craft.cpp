#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
const int MX = 1002;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        // 배열, 벡터, 큐 초기화
        int d[MX]={0,};
        int in[MX]={0,};
        int ans[MX]={0,};
        vector<int>adj[MX];
        int N,K,W;
        cin >> N >> K;

        for(int i=1;i<=N;i++){
            cin >> d[i];
        }

        for(int i=0;i<K;i++){
            int a,b;
            cin >> a >>b;

            adj[a].push_back(b);
            in[b]++;
        }

        cin >> W;
        queue<int>q;
        for(int i=1;i<=N;i++){
            if(in[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int i=0;i<adj[cur].size();i++){
                int nx = adj[cur][i];
                ans[nx] = max(ans[nx],d[cur] + ans[cur]);
                in[nx]--;

                if(in[nx] == 0){
                    q.push(nx);
                }
            }
        }

        cout << ans[W]+d[W] << '\n';
    }

    

    return 0;
}