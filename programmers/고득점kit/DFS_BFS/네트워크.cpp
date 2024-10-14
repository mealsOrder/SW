#include<string>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
const int MX = 201;
bool vis[MX];
vector<int>adj[MX];

void BFS(int x){
    queue<int>q;
    vis[x] = true;
    q.push(x);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=0;i<adj[cur].size();i++){
            int nx = adj[cur][i];
            
            if(!vis[nx]){
                vis[nx]=true;
                q.push(nx);
            }
        }
    }
}
int solution(int n, vector<vector<int>>c) {
    int ans = 0;
    
    for(int i=0;i<c.size();i++){
        for(int j=0;j<c[i].size();j++){
            // 인접리스트 구성 오류
            // c[i][j] == 1일 때만 연결되어야 하고 i=j 일때 는 넘어가야함
            if(i != j && c[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);            
            }
        }
    }
    
    // 노드는 2중 포문 돌 필요가 없음 굳이 필요없는 for문 삭제
    for(int i=0;i<n;i++){
        if(!vis[i]){
            BFS(i);
            ans++;
        }
    }
    
    return ans;
}
