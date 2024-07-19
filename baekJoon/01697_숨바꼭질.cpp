#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 100001;
int dist[MX];
bool visited[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin >>N>>K;

    queue<int>q;
    dist[N] = 0;
    visited[N] = true;
    q.push(N);
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == K) break; // 종료 조건

        for(int nxt : {cur-1,cur+1,2*cur}){
            if(nxt>=0 && nxt<=100000 && !visited[nxt]){
                visited[nxt]=true;
                dist[nxt] = dist[cur]+1;
                q.push(nxt);
            }
        }
    }
    cout << dist[K];
    return 0;
}