#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
const int MX = 100002;

int N;
vector<int>p;
vector<tuple<int,int,int>>t;
pair<int,int> x[MX];
pair<int,int> y[MX];
pair<int,int> z[MX];
int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

bool Union(int x,int y){
    x = Find(x);
    y = Find(y);

    if(x == y) return false;

    if(y>x) p[y]=x;
    else p[x] = y;

    return true;
}

void kruskal(){
    sort(t.begin(),t.end());
    int connected=0;
    int ans = 0;

    for(auto &edge:t){
        int cost,from,to;
        tie(cost,from,to) = edge;

        if( Union(from,to)){
            ans+=cost;
            connected++;

            if(connected == N-1) break;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N;

    p.resize(N+1);
    for(int i=1;i<=N;i++) p[i] = i;

    for(int i=0;i<N;i++){
        int cx,cy,cz;
        cin >>cx >> cy>> cz;
        x[i] = {cx,i};
        y[i] = {cy,i};
        z[i] = {cz,i};
    }

    sort(x, x + N);
    sort(y, y + N);
    sort(z, z + N);

    for(int i=1;i<N;i++){
        t.push_back({abs(x[i].first - x[i - 1].first), x[i].second, x[i - 1].second});
        t.push_back({abs(y[i].first - y[i - 1].first), y[i].second, y[i - 1].second});
        t.push_back({abs(z[i].first - z[i - 1].first), z[i].second, z[i - 1].second});
    }
    kruskal();
    return 0;
}