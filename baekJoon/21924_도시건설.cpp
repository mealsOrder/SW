#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

typedef long long ll;
vector<int>p;
vector<tuple<int,int,int>>t;
int N,M;

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int x,int y){
    x = Find(x);
    y = Find(y);
    if(y>x) p[y]=x;
    else p[x]=y;
}

ll kruskal(){
    sort(t.begin(),t.end());
    int connected = 0;
    ll ans = 0;

    for(auto edge:t){
        ll cost;
        int from,to;
        tie(cost,from,to) = edge;

        if(Find(from)!=Find(to)){
            Union(from,to);
            ans+=cost;
            connected++;
            
        }
    }
    if(connected == N-1) return ans;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    ll total = 0;
    p.resize(N+1);
    for(int i=1;i<=N;i++)p[i]=i;
    while(M--){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        total+=c;
        t.push_back({c,a,b});
    }
    ll res = kruskal();
    if(res == -1) cout << res << '\n';
    else cout << total-res << '\n';

    
    return 0;
}