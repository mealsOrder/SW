#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <tuple>
using namespace std;

const int INF = 1e9;

vector<tuple<int,int,int>>v;

int N,M,W;
int dist[501];
bool bellman_ford(){
    dist[1] = 0;

    for(int i=1;i<=N;i++){
        for(int j=0;j<v.size();j++){
            int from,to,cost;
            tie(from,to,cost) = v[j];

            if(dist[from] == INF)continue;

            if(dist[to] > dist[from] + cost){
                dist[to] = dist[from] + cost;

                if(i == N) return true;
            }
        }
    }

    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        cin >> N >> M >> W;
        
        v.clear();
        fill(dist,dist+N+1,INF);

        // 도로 정보
        for(int i=0;i<M;i++){
            int a,b,c;
            cin >> a >> b >> c;
            v.push_back({a,b,c});
            v.push_back({b,a,c});

        }

        // 웜홀 정보
        for(int i=0;i<W;i++){
            int a,b,c;
            cin >> a >> b >> c;
            v.push_back({a,b,c*-1});
        }

        if( bellman_ford() ) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}