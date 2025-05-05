#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

const int MX = 100002;

vector<tuple<int,int,int>>t;
vector<int>parent;
pair<int,int> x[MX];
pair<int,int> y[MX];
pair<int,int> z[MX];
int N;

int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x == y) return false;
    if(x<y) parent[y] = x;
    else parent[x]=y;
    return true;
}

void kruskal(){
    sort(t.begin(),t.end());
    int ans = 0;
    int connected = 0;

    for(auto &edge:t){
        int cost;
        int from,to;
        tie(cost,from,to) = edge;
        if(Union(from,to)){
            ans += cost;
            connected++;
            if(connected == N-1) break;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    parent.resize(N+1);
    for(int i=1;i<=N;i++)parent[i] = i;

    for(int i=0;i<N;i++){
        int cx,cy,cz;
        cin >> cx >> cy >> cz;
        x[i] = {cx, i};
        y[i] = {cy, i};
        z[i] = {cz, i};
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