#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<deque>
using namespace std;
const int MX = 200001;
const int INF = INT_MAX;
int N,K;
int dist[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N>>K;

    fill(dist,dist+MX,-1);
    deque<int>dq;
    dist[N]=0;
    dq.push_back(N);

    while(!dq.empty()){
        int cur = dq.front();
        dq.pop_front();

        if(cur*2 < MX && dist[cur*2] == -1){
            dist[cur*2] = dist[cur];
            dq.push_front(cur*2);
        }
        for(int next : {cur-1,cur+1}){
            if(next < 0 || next >=MX || dist[next] != -1) continue;
            dist[next] = dist[cur]+1;
            dq.push_back(next);
        }
    }

    cout << dist[K] << '\n';
    
    return 0;
}