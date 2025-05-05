#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
vector<tuple<int, int, int>> t; 
vector<int> parent;

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    
    if (x == y) return false;
    if (x < y) parent[y] = x;
    else parent[x] = y;
    return true;
}

int kruskal() {
    int ans = 0;
    int connected = 0;
    for (auto edge : t) {
        
        int cost, from, to;
        tie(cost, from, to) = edge;

        if(Union(from, to)) {
            ans += cost;
            connected++;
            if (connected == N-1 ) break;
        }
    }
    return ans;
}

int main() {
    cin >> N >> M;
    
    parent.resize(N+1);
    for (int i = 0; i <=N; i++) parent[i] = i;

    int fa,fb,fc,st;
    cin >> fa>>fb>>fc;

    if(fc == 0) st = 1;
    else st = 0;
    

    for(int i=1;i<=M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        t.push_back({!c,a,b});
    }
    
    sort(t.begin(), t.end(),greater<>());
    int mx = kruskal()+st;
    //cout << mx << '\n';

    parent.resize(N+1);
    for (int i = 0; i <=N; i++) parent[i] = i;
    sort(t.begin(), t.end());
    int mn = kruskal()+st;
    //cout << mn << '\n';
    int res = mx*mx - mn*mn;
    cout << res <<'\n';
    return 0;
}
