#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<deque>
using namespace std;
/**
 * DFS 풀이
 */
const int MX = 51;
int N;
int ans;
vector<int> v[MX];
bool vis[MX];

void init(){
    for(int i=0;i<N;i++) vis[i] = false;
}
void DFS(int fCnt,int x){
    vis[x] = true;
    if(fCnt == 2) return;
    for(int i=0;i<v[x].size();i++){
        int nx = v[x][i];
        DFS(fCnt+1,nx);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    char s;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> s;
            if(s == 'Y') v[i].push_back(j);
        }
    }

    for(int i=0;i<N;i++){
        int cnt = 0;
        init();
        DFS(0,i);
        for(int k=0;k<N;k++){
            if(vis[k])cnt++;
        }
        ans = max(ans,cnt);
    }
    cout << ans -1 << '\n';
    return 0;
}