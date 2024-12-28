#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
const int MX = 10001;
int N,M;
vector<tuple<int,int,int>>t ;
int parent[MX];
int ans;

bool cmp(tuple<int,int,int> &a, tuple<int,int,int>&b){
    return get<0>(a) < get<0>(b);
}

int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int u,int v){
    u = Find(u);
    v = Find(v);

    if(u>v) parent[u] = v;
    else parent[v] = u;
}
bool isSameParent(int u,int v){
    u = Find(u);
    v = Find(v);

    if(u==v) return true;
    else return false;
}

void kruskal(){
    for(int i=0;i<t.size();i++){
        int cost = get<0>(t[i]);
        int u = get<1>(t[i]);
        int v = get<2>(t[i]);
        if(!isSameParent(u,v)){
            Union(u,v);
            ans += cost;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for(int i=1;i<=N;i++){
        parent[i] = i;
    }

    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;

        t.push_back({c,a,b});
    }

    sort(t.begin(),t.end(),cmp);
    
    kruskal();

    return 0;
}