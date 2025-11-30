#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
using namespace std;
const int MX = 1001;
int N,M,K;
vector<tuple<int,int,int>>t;
vector<int>p;
vector<pair<int,int>>v[MX]; // [from] { w, to}

bool vis[MX];
int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int x,int y){
    x = Find(x);
    y = Find(y);
    if(y>x)p[y]=x;
    else p[x]=y;
}

void kruskal(){
    sort(t.begin(),t.end(),greater<>());
    int con = 0;
    
    for(auto edge:t){
        int w,from,to;
        tie(w,from,to) = edge;

        if(Find(from) != Find(to)){
            Union(from,to);
            v[from].push_back({w,to});
            v[to].push_back({w,from});
            con++;

            if(con == N-1) break;
        }
        
    }
}
void BFS(int start, int target) {
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int, int>> pq; // {w, node}
    pq.push({987987987, start});
    int minW = 987987987;

    while (!pq.empty()) {
        int curW = pq.top().first;
        int curX = pq.top().second;
        pq.pop();

        if (vis[curX]) continue;
        vis[curX] = true;
        minW = min(minW, curW);

        if (curX == target) {
            cout << minW << '\n';
            return;
        }

        for (int i = 0; i < v[curX].size(); i++) {
            int nw = v[curX][i].first;
            int nx = v[curX][i].second;

            if (!vis[nx]) {
                pq.push({nw, nx});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    p.resize(N+1);
    for(int i=1;i<=N;i++)p[i]=i;
    while(M--){
        int a,b,c;
        cin >> a >> b>> c;
        t.push_back({c,a,b});
    }

    kruskal();

    while(K--){
        int x,y;
        cin >> x >> y;
        BFS(x,y);
    }

    return 0;
}
