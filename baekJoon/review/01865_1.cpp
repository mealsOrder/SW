#include<iostream>
#include<vector>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;
const int MX = 501;
const int INF = 1e9;
vector<tuple<int,int,int>>v;
int dist[MX];
int T,N,M,W;
bool bellman_ford(int x){
    fill(dist,dist+N+1,INF);
    dist[x] = 0;

    for(int i=1;i<N;i++){
        for(auto t : v){
            int from,to,cost;
            tie(from,to,cost) = t;
            // if( dist[from] == INF) continue; // 최소 한번은 from 에서 계산을 해야 한다
            if( dist[to] > dist[from] + cost){
                dist[to] = dist[from] + cost;
            }
        }
    }

    for(auto t : v){
        int from,to,cost;
        tie(from,to,cost) = t;
        // if( dist[from] == INF) continue;
        if( dist[to] > dist[from] + cost){
            return true;
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> T;

    while(T--){
        cin >> N >> M >> W;
        v.clear();

        for(int i=0;i<M;i++){
            int a,b,c;
            cin >> a >> b >> c;

            v.push_back({a,b,c});
            v.push_back({b,a,c});
        }

        for(int i=0;i<W;i++){
            int a,b,c;
            cin >> a >> b >> c;
            v.push_back({a,b,c*-1});
        }

        bool cycle = bellman_ford(1);

        if(cycle) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}