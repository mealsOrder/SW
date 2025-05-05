#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

const int MX = 10001;

int N,M,T;
vector<int>p;
vector<tuple<int,int,int>>t;

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int x,int y){
    x = Find(x);
    y = Find(y);

    if(y>x) p[y] = x;
    else p[x] = y;
}

void kruskal(){
    int connected = 0;
    int ans = 0;
    sort(t.begin(),t.end());

    for(auto& edge:t){
        int cost,from,to;
        tie(cost,from,to) = edge;

        if(Find(from) != Find(to)){
            Union(from,to);
            ans += cost + connected*T;
            connected++;

            if(connected == N-1){
                cout << ans;
                return;
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> T;

    p.resize(N+1);
    for(int i=1;i<=N;i++)p[i] = i;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        t.push_back({c,a,b});
    }
    kruskal();
    return 0;
}