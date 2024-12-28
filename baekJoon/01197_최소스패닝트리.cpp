#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;

int V,E,ans;
vector<int>parent;
vector<tuple<int,int,int>>t;
int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x<y) parent[y] = x;
    else parent[x] = y;
}

void kruskal(){
    sort(t.begin(),t.end());
    parent.resize(V+1);

    for(int i=1;i<=V;i++) parent[i]=i;

    for(auto& edge : t){
        int cost = get<0>(edge);
        int from = get<1>(edge);
        int to = get<2>(edge);

        if( Find(from) != Find(to)){
            Union(from,to);
            ans += cost;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> V >> E;

    for(int i=0;i<E;i++){
        int a,b,c;
        cin >> a >> b >> c;
        t.push_back({c,a,b});
    }
    kruskal();
    cout << ans << '\n';
    return 0;
}