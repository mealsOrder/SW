#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, int>P;

struct Node{
    int index;
    ll x, y;
};

double dist(const Node& a, const Node& b){
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<Node>nodes(N);
    for(int i = 0; i < N; ++i){
        cin >> nodes[i].x >> nodes[i].y;
        nodes[i].index = i;
    }

    vector<vector<pair<int, double>>> graph(N);

    // 초기 도로: 1-2, 2-3, ..., N-1 - N
    for(int i = 0; i < N - 1; ++i){
        double d = dist(nodes[i], nodes[i + 1]);
        graph[i].push_back({i + 1, d});
        graph[i + 1].push_back({i, d});
    }

    // x좌표 기준 정렬 후 인접 노드 간선 추가
    sort(nodes.begin(), nodes.end(), [](const Node& a, const Node& b){
        return a.x < b.x;
    });
    for(int i = 0; i < N - 1; ++i){
        double d = dist(nodes[i], nodes[i + 1]);
        graph[nodes[i].index].push_back({nodes[i + 1].index, d});
        graph[nodes[i + 1].index].push_back({nodes[i].index, d});
    }

    // y좌표 기준 정렬 후 인접 노드 간선 추가
    sort(nodes.begin(), nodes.end(), [](const Node& a, const Node& b){
        return a.y < b.y;
    });
    for(int i = 0; i < N - 1; ++i){
        double d = dist(nodes[i], nodes[i + 1]);
        graph[nodes[i].index].push_back({nodes[i + 1].index, d});
        graph[nodes[i + 1].index].push_back({nodes[i].index, d});
    }

    // 다익스트라 시작
    vector<double> dists(N, 1e18);
    priority_queue<P, vector<P>, greater<P>>pq;
    dists[0] = 0;
    pq.push({0.0, 0});

    while(!pq.empty()){
        double curCost;
        int cur;
        tie(curCost,cur) = pq.top(); pq.pop();
        if(dists[cur] < curCost) continue;
        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i].first;
            double cost= graph[cur][i].second;
            if(dists[next] > dists[cur] + cost){
                dists[next] = dists[cur] + cost;
                pq.push({dists[next], next});
            }
        }
    }

    cout << fixed << setprecision(10) << dists[N - 1] << '\n';
    return 0;
}
