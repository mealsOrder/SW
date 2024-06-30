#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
#define INF 987654321
using namespace std;

void dijkstra(int start, int end, vector<vector<pair<int,int>>>& map, vector<int>& cost) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    
    while(!pq.empty()) {
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        
        if(curNode == end) return;
        
        for(auto& next : map[curNode]) {
            int nextDist = curDist + next.second;
            int nextNode = next.first;
            
            if(nextDist < cost[nextNode]) {
                cost[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int shortCutCount, roadLength;
    cin >> shortCutCount >> roadLength;
    
    vector<vector<pair<int,int>>> map(MAX);
    vector<int> cost(MAX, INF);
    
    // 고속도로 정보 입력
    for(int i = 0; i < roadLength; i++) {
        map[i].push_back({i+1, 1});
    }
    
    // 지름길 정보 입력
    for(int cnt = 0; cnt < shortCutCount; cnt++) {
        int from, to, distance;
        cin >> from >> to >> distance;
        if(to > roadLength || from > roadLength || ((to-from) < distance)) continue;
        map[from].push_back({to, distance});
    }
    
    dijkstra(0, roadLength, map, cost);
    cout << cost[roadLength];
    
    return 0;
}
