#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
const int MX = 100002;
int N,K;
int dist[MX];
int ans = 0;
queue<int>q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >>N>>K;

    fill(dist,dist+MX,-1);
    dist[N]=0;
    q.push(N);

    while(dist[K] == -1){
        int cur = q.front();
        q.pop();

        for(int nxt : {cur-1,cur+1,cur*2}){
            if(nxt<0 || nxt>100000)continue;
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur]+1;
            q.push(nxt);
        }
    }
    cout << dist[K];
    
    return 0;
}