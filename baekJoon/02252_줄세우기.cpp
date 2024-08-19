#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MX = 32003;
queue<int>q;
vector<int>adj[MX];
int inDegree[MX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;
    while(M--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        inDegree[b]++;
    }
    for(int i=1;i<=N;i++){
        if(inDegree[i] == 0)q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int i=0;i<adj[cur].size();i++){
            int nx = adj[cur][i];
            inDegree[nx]--;
            if(inDegree[nx]==0){
                q.push(nx);
            }
        }
    }
    return 0;
}