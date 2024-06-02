#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 1000001;
int dist[MX];
int dir[2];
queue<int>q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int F,S,G,U,D;
    cin >>F>>S>>G>>U>>D;
    dir[0] = U;
    dir[1] = -1*D;
    fill(dist,dist+F+5,-1);
    dist[S] = 0;
    q.push(S);
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0;i<2;i++){
            int nx = cur + dir[i];

            // 벗어난 범위
            if(nx<1||nx>F) continue;
            if(dist[nx] >= 0)continue;
            dist[nx] = dist[cur]+1;
            q.push(nx);
        }
    }
    if(dist[G] == -1)cout << "use the stairs\n";
    else cout << dist[G] << '\n';
    return 0;
}