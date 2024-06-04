#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
using namespace std;
const int MX = 102;
vector<int>v[MX];
bool vis[MX];
queue<int>q;
int cnt;
void BFS(int x){
    vis[x]=true;
    q.push(x);

    while(!q.empty()){
        int curX = q.front();
        q.pop();

        for(auto nxt : v[curX]) {
            if(vis[nxt])continue;
            q.push(nxt);
            vis[nxt]=true;
            cnt++;
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
    cout << cnt << '\n';
    return 0;
}
