#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
const int MX = 100001;
int N;
vector<pair<int,int>>v[MX];
int mxDist;
int mxNode;
bool vis[MX];
void DFS(int x,int d){
    
    if(vis[x]) return;
    vis[x] = true;
    
    if(mxDist < d){
        mxDist = d;
        mxNode = x;
    }

    for(int i=0;i<v[x].size();i++){
        int nxNode = v[x][i].first;
        int nxDist = v[x][i].second;

        DFS(nxNode,d+nxDist);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        while(1){
            int b;
            cin >> b;

            if( b == -1) break;

            int c;

            cin >> c;

            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
    }

    DFS(1,0);
    fill(vis,vis+N+1,0);
    DFS(mxNode,0);

    cout << mxDist << '\n';

    return 0;
}