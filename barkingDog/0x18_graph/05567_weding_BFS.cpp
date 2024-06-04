#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
using namespace std;
const int MX = 501;
vector<int>v[MX];
int vis[MX];
queue<int>q;
int par[MX];
int cnt;
// 부모가 1이거나 부모의 부모가 1인 노드에서 카운트 증가
void BFS(int x){
    vis[x] = true;
    q.push(x);

    while(!q.empty()){
        int curX = q.front();
        q.pop();

        for(int i=0;i<v[curX].size();i++){
            int nx = v[curX][i];
            if(par[nx] == 0){
                par[nx] = curX;
            }
            
            if(vis[nx]) continue;

            vis[nx]=true;
            q.push(nx);
            if(par[nx] == 1 || par[par[nx]] == 1){
                cnt++;
            }    
        }
    }
}

int main(){
    int N,M;
    cin >>N>>M;

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    BFS(1);
    cout << cnt;
    return 0;
}
