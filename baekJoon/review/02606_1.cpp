#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 101;
vector<int>v[MX];
bool vis[MX];
int cnt;
void DFS(int curNode){
    vis[curNode] = true;
    cnt++;
    for(int i=0;i<v[curNode].size();i++){
        int nxNode = v[curNode][i];

        if(!vis[nxNode]){ // vis[nxNode] == false
            DFS(nxNode);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N,M;
    cin >> N >> M;

    while(M--){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DFS(1);
    cout << cnt - 1 << '\n';
    return 0;
}