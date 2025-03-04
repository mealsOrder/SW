#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<tuple>
using namespace std;

int N,M,K;
vector<int>parent;
vector<tuple<int,int,int>>t;


int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x,int y){
    x = Find(x);
    y = Find(y);

    if(x<y) parent[y] = x;
    else parent[x] = y;
}

int kruskal(){
    int ans = 0;
    int connect = 0;
    sort(t.begin(),t.end());

    for(auto& edge:t){
        int cost,from,to;
        tie(cost,from,to) = edge;

        if(Find(from) != Find(to)){
            Union(from,to);
            ans+=cost;
            connect++;

            if(connect == N-K) break;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> M >> K;
    parent.resize(N+1);
    for(int i=1;i<=N;i++) parent[i] = i;

    vector<int>p(K);

    for(int i=0;i<K;i++){
        cin >> p[i];
    }

    for(int i=1;i<K;i++){
        Union(p[0],p[i]);
    }

    for(int i=0;i<M;i++){
        int u,v,w;
        cin >> u >> v >> w;
        t.push_back({w,u,v});
    }
    cout << kruskal() << '\n';
       
    return 0;
}