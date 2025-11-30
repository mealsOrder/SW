#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
using namespace std;
const int MX = 100001;
const int INF = 1e9;
int A,B,N,M;
int dis[MX];
void BFS(int x){
    queue<int>q;
    q.push(x);
    dis[x] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == M) return;
        for(int nx : {cur-1,cur+1,cur+A,cur-A,cur+B,cur-B,cur*A,cur*B}){
            if(nx<0 || nx>100000)continue;
            if(dis[nx] > dis[cur] + 1){
                dis[nx] = dis[cur]+1;
                q.push(nx);
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> A >> B >> N >> M;

    fill(dis, dis + MX, INF);
    BFS(N);

    cout << dis[M] -1<<'\n';
    return 0;
}
