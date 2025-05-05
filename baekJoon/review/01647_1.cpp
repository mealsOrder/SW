#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>

using namespace std;

int N,M;
vector<int>parent;
vector<tuple<int,int,int>>t;

int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);

    if( x < y) parent[y] = x;
    else parent[x] = y;
}

void kruskal(){
    int connected = 0;
    int mxCost = 0;
    int ans = 0;
    sort(t.begin(),t.end());

    for(auto & edge : t){
        int cost,from,to;
        tie(cost,from,to) = edge;

        if(Find(from)!= Find(to)){
            Union(from,to);
            ans+=cost;
            connected++;
            mxCost = cost;

            if(connected == N-1)break;
        }
    }
    cout << ans - mxCost <<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        t.push_back({c,a,b});
    }
    parent.resize(N+1);
    for(int i=1;i<=N;i++)parent[i] = i;

    kruskal();
    return 0;
}