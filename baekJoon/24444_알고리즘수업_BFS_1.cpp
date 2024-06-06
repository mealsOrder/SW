#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 100009;
queue<int>q;
vector<int>v[MX];
int N,M,R;
int dist[MX];
int cnt;
void BFS(int x){
    dist[x]=1;
    cnt = 1;
    q.push(x);
    while(!q.empty()){
        int curX = q.front();
        q.pop();

        sort(v[curX].begin(),v[curX].end());
        
        for(int i=0;i<v[curX].size();i++){
            int nx = v[curX][i];
            
            if( dist[nx] ) continue;
            dist[nx] = ++cnt;
            q.push(nx);

        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N>> M>>R;

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    BFS(R);
    for(int i=1;i<=N;i++){
        cout << dist[i]<<'\n';
    }
    return 0;
}