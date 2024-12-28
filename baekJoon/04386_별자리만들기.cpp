#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<cmath>
using namespace std;
int N;
vector<pair<float,float>>v;
vector<tuple<float,int,int>>t;
vector<int>parent;
float ans;
float cal(int a_idx, int b_idx ){
    float apow = (v[a_idx].first - v[b_idx].first) * (v[a_idx].first - v[b_idx].first);
    float bpow = (v[a_idx].second - v[b_idx].second) * (v[a_idx].second - v[b_idx].second);
    return sqrt( apow + bpow );
}


int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x,int y){
    x = Find(x);
    y = Find(y);

    if(x < y) parent[y] = x;
    else parent[x] = y;
}

void kruskal(){
    sort(t.begin(),t.end());
    parent.resize(N+1);

    for(int i=1;i<=N;i++)parent[i]=i;

    for(auto& edge:t){
        float cost = get<0>(edge);
        int from = get<1>(edge);
        int to = get<2>(edge);

        if(Find(from) != Find(to)){
            Union(from,to);
            ans += cost;
        }
    }
}
int main(){
    cin >> N;

    for(int i=0;i<N;i++){
        float a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            float dist = cal (i,j); 
            t.push_back({dist,i+1,j+1});
        }
    }
    kruskal();
    printf("%.2f\n",ans);
    return 0;
}