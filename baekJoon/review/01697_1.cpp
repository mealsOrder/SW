#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<deque>
using namespace std;
const int MX = 100001;
int N,K;
int dist[MX];
int BFS(int x){
    queue<int>q; // {노드,시간}
    q.push(x);
    dist[x] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == K) return dist[K];

        for(int nxt: {cur-1,cur+1,cur*2}){
            if(nxt >=0 && nxt<MX && dist[nxt] == -1){
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    fill(dist,dist+MX,-1);
    int ans = BFS(N);
    
    cout << ans << '\n';
    return 0;
}