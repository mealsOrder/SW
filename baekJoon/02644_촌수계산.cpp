#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 102;

queue<int>q;
vector<int>v[MX];
int vis[MX];
int BFS(int x,int y){
    vis[x]=0;
    q.push(x);
    while(!q.empty()){
        int curX = q.front();
        q.pop();
        if(curX == y) return vis[curX];

        for(int i=0;i<v[curX].size();i++){
            int nx = v[curX][i];

            if(vis[nx]>=0)continue;
            vis[nx] = vis[curX]+1;
            q.push(nx);
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N;
    int st,en;
    cin >>st>>en;
    fill(vis,vis+N+2,-1);
    cin >> M;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int res = BFS(st,en);
    cout << res << '\n';
    return 0;
}