#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MX = 1001;
int N, M;
 
int inDegree[MX];
vector<int>adj[MX];
vector<int>ans;
 
void topologicalSort(){
    queue<int> q;
 
    for(int i = 1; i <= N; i++){
        if(!inDegree[i])
            q.push(i);
    }
 
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
 
        for(int i = 0; i < adj[cur].size(); i++){
            int nx = adj[cur][i];
            inDegree[nx]--;
 
            if(!inDegree[nx]){
                q.push(nx);
            }
        }
    }
}
 
int main(){
    cin >> N >> M;
 
    for(int i = 0; i < M; i++){
        int cur;
        int prev;
        cin >> cur;
        cin >> prev;
        for(int j = 0; j < cur - 1; j++){
            int a;
            cin >> a;
            adj[prev].push_back(a);
            inDegree[a]++;
            prev = a;
        }
    }
 
    topologicalSort();
 
    if(ans.size() != N){
        cout << 0;
    }
    else{
        for(int i = 0; i < N; i++){
            cout << ans[i] << "\n";
        }
    }
}