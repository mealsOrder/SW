#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> p;
vector<tuple<double, int, int>> t; 
vector<int> parent;
int connected;
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

void kruskal() {
    sort(t.begin(), t.end());
    double ans = 0;  

    for (auto edge : t) {
        double cost;
        int from, to;
        tie(cost, from, to) = edge;

        if (Union(from, to)) {
            ans += cost;
            connected++;
            if (connected == N - 1) break;
        }
    }
    printf("%.2lf\n", round(ans * 100) / 100);
}

int main() {
    cin >> N >> M;
    
    parent.resize(N);
    for (int i = 0; i < N; i++) parent[i] = i;

    p.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i].first >> p[i].second;
    }

    int connected = 0;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (Union(a - 1, b - 1)) connected++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double cost = sqrt(pow(p[i].first - p[j].first, 2) + pow(p[i].second - p[j].second, 2));  // 올바른 연산 방식
            t.push_back({cost, i, j});
        }
    }

    kruskal();
    return 0;
}
