#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<cstring>

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

void kruskal(){
    int ans=0;
    int connected = 0;
    sort(t.begin(),t.end());

    for(auto & edge:t){
        int cost,from,to;
        tie(cost,from,to) = edge;

        if(Find(from) != Find(to)){
            Union(from,to);
            ans+=cost;
            connected++;

            if(connected == N-K)break;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    parent.resize(N+1);
    for(int i=1;i<=N;i++) parent[i] = i;
        
    for(int i=0;i<K;i++){
        int a;
        cin >> a;
        Union(0,a);
    }

    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        t.push_back({c,a,b});
    }

    kruskal();
    return 0;
}