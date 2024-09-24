#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 55;
int N,root,ans;
vector<int> v[MX];
int vis[MX];

void DFS(int x){
    int tmp = 0;
    if(vis[x]) return;
    vis[x] = 1;

    for(int i=0;i<v[x].size();i++){
        int nx = v[x][i];
        if(!vis[nx]){
            DFS(nx);
            tmp++;
        }
    }
    if(tmp == 0) ans++;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        if(a == -1)root = i;
        else v[a].push_back(i);

    }
    int K;
    cin >> K;
    DFS(K);
    ans=0;
    DFS(root);
    if(K == root) cout << 0 << '\n';
    else cout << ans << '\n';

    return 0;
}