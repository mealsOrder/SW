#include<iostream>
#include<vector>

using namespace std;
const int MX = 10'001;
vector<pair<int,int>>v[MX];
bool vis[MX];
int N,mxNode,mxDist;
void DFS(int node,int dist){
    if(vis[node])return;
    vis[node] = true;
    
    if(dist > mxDist ){
        mxDist = dist;
        mxNode = node;
    }

    for(int i=0;i<v[node].size();i++){
        int nxNode = v[node][i].first;
        int nxDist = v[node][i].second;

        DFS(nxNode,dist+nxDist);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int T = N-1;

    while(T--){
        int a,b,c;
        cin >> a>>b>>c;

        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    DFS(1,0); // 시작 노드, 거리
    // init
    fill(vis,vis+N+1,0);
    DFS(mxNode,0);

    cout << mxDist << '\n';

    return 0;
}