#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
using namespace std;

const int MX = 200001;
int N,K;
int dist[MX];
int BFS(){
    deque<int>dq;
    dist[N] = 0;
    dq.push_back(N);

    while(!dq.empty()){
        int cur = dq.front();
        dq.pop_front();
        if(cur == K) return dist[K];
        if(cur*2 < MX && dist[cur*2] == -1){
            dist[cur*2] = dist[cur];
            dq.push_front(cur*2);
        }

        for(int nxt : {cur-1,cur+1}){
            if(nxt<0 || nxt >= MX || dist[nxt] != -1 )continue;
            dist[nxt] = dist[cur]+1;
            dq.push_back(nxt);
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> N >>K;
    fill(dist,dist+MX,-1);
    int ans = BFS();
    cout << ans << '\n';
	return 0;
}
