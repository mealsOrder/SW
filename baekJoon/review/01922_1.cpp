#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

int N,M;
vector<tuple<int,int,int>>t;
vector<int>p;

int Find(int x){
    if(x == p[x])return x;
    return p[x] = Find(p[x]);
}

void Union(int x,int y){
    x = Find(x);
    y = Find(y);

    if(y>x)p[y]=x;
    else p[x]=y;
}

int kruskal(){
    sort(t.begin(),t.end());
    int ans = 0;
    int connected = 0;

    for(auto edge:t){
        int cost,from,to;
        tie(cost,from,to)=edge;

        if(Find(from)!=Find(to)){
            Union(from,to);
            ans+=cost;
            connected++;
        }
        if(connected == N-1) return ans;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    p.resize(N+1);
    for(int i=1;i<=N;i++)p[i]=i;
    while(M--){
        int a,b,c;
        cin >> a >> b >> c;
        t.push_back({c,a,b});
    }

    int res = kruskal();
    cout << res << '\n';
    return 0;
}
