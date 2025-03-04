#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<tuple>
using namespace std;
int N,ans;
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
    int connected = 0;
    sort(t.begin(),t.end());
    
    for(auto &edge : t){
        int c,from,to;
        tie(c,from,to) = edge;

        if (Find(from) != Find(to)) {
            Union(from, to);
            ans += c;
            connected++;

            if(connected == N-1) break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N;
    parent.resize(N);
    for(int i=0;i<N;i++) parent[i] = i;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int cost;
            cin >> cost;
            if(i <j)t.push_back({cost,i,j});
        }
    }
    kruskal();
    cout << ans << '\n';   
    return 0;
}