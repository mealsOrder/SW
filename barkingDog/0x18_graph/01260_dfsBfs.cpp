#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<stack>
using namespace std;

const int MX = 1005;
vector<int>v[MX];
queue<int>q;
int vis[MX];
int N,M,S;

// 비재귀 DFS
void dfs1(){
    stack<int> s;
    s.push(S);
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        if(vis[cur]) continue;
        vis[cur] = true;
        cout << cur << ' ';
        for(int i = 0; i < v[cur].size(); i++){
        // 스택의 특성상 정점을 역순으로 넣어야 함
        int nxt = v[cur][v[cur].size()-1-i];
        if(vis[nxt]) continue;
        s.push(nxt);
        }    
    }
}
void DFS(int x){
    vis[x]=true;
    cout << x << " ";
    for(int i=0;i<v[x].size();i++){
        int nx = v[x][i];

        if(!vis[nx]){
            DFS(nx);
        }
    }
}

void BFS(int x){
    vis[x]=true;
    q.push(x);
    
    while(!q.empty()){
        int curX = q.front();
        cout << curX << " ";
        q.pop();
        
        for(int i=0;i<v[curX].size();i++){
            int nx = v[curX][i];

            if(!vis[nx]){
                
                vis[nx]=true;
                q.push(nx);
                
            }
        }
    }
}
int main() {
    cin >> N>>M>>S;

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a>>b;

        v[a].push_back(b);
        v[b].push_back(a);

    }
    for(int i=0;i<=N;i++) sort(v[i].begin(),v[i].end());
    DFS(S);
    fill(vis,vis+N+2,0);
    cout << '\n';
    BFS(S);


    return 0;
}