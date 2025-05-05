#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<int>parent;
vector<tuple<int,int,int>>t;

int N,ans;

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);

    if(y>x) parent[y] = x;
    else parent[x] = y;
}

void kruskal(){
    sort(t.begin(),t.end());
    parent.resize(N+1);

    for(int i=1;i<=N;i++)parent[i] = i;

    for(auto& edge:t){
        int cost = get<0>(edge);
        int from = get<1>(edge);
        int to = get<2>(edge);
        //tie(cost,from,to) = edge;

        if( Find(from) != Find(to)){
            Union(from,to);
            ans+=cost;
        }

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        t.push_back({a,0,i+1});
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int cost;
            cin >> cost;
            if(i!=j) t.push_back({cost,i,j});
        }
    }
    kruskal();
    cout << ans << '\n';
    return 0;
}
