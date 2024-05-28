#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MX = 100001;
bool visited[MX];
int ans[MX];
vector<int>v[MX];
void DFS(int x){
    if(visited[x])return;
    visited[x]=true;
    for(int i=0;i<v[x].size();i++){
        int nx = v[x][i];
        if(ans[nx])continue;
        ans[nx] = x;
        if(!visited[nx]){
            //ans[nx] = x;
            DFS(nx);
        }
    }
}

int main() {
    int N;
    cin >> N;
    for(int i=1;i<=N-1;i++){
        int a,b;
        cin >> a>>b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1);
    for(int i=2;i<=N;i++)cout << ans[i] <<'\n';
    return 0;
}