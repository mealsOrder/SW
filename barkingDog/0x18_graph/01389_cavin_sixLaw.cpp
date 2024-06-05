#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
const int MX = 101;
const int INF = INT_MAX;
int mn = INF;
int ans;
vector<int>v[MX];
int dist[MX];
int BFS(int x){
    queue<int>q;
    dist[x]=0;
    int sum=0;
    q.push(x);
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0;i<v[cur].size();i++){
            int nx = v[cur][i];

            if(dist[nx]>=0)continue;
            
            dist[nx] = dist[cur]+1;
            sum += dist[nx];
            q.push(nx);
        }
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    cin >>N>>M;

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }    
    int idx=0;
    for(int i=1;i<=N;i++){
        fill(dist,dist+N+2,-1);
        ans = BFS(i);
        if(mn > ans){
            mn = ans;
            idx = i;
        }
    }
    cout << idx;
    return 0;
}
