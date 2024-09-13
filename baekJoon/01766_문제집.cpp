#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MX = 32002;
int N,M;
vector<int>adj[MX];
priority_queue< int, vector<int>, greater<int>>pq;
int inDegree[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    while(M--){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        inDegree[b]++;
    }

    for(int i=1;i<=N;i++){
        if(inDegree[i] == 0)pq.push(i);
    }

    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        cout << cur << " ";
        for(int i=0;i<adj[cur].size();i++){
            int nx = adj[cur][i];
            inDegree[nx]--;

            if(inDegree[nx] == 0)pq.push(nx);
        }
    }


    return 0;
}