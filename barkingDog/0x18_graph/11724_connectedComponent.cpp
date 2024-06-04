#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
using namespace std;
/**
 * V : 정점의 갯수
 * E : 간선갯수
 *                              인접 행렬    인접리스트
 *                    공간복잡도   O(v^2)       O(V+E)
 *             정점 u,v연결 확인   O(1)         O(min(deg(u),deg(v)))
 * 정점 v와 연결된 모든 정점 확인   O(V)         O(deg(v))
 *                 효율적인 상황     (1)          (2)
 * (1) 두 점의 연결여부를 자주 확인할때, E기 V^2에 가까울때
 * (2) 특정 정점에 연결된 모든 정점을 자주 확인할 때, E기 v^2보다 훨씬 작을때
*/
const int MX = 1001;
vector<int>v[MX];
int vis[MX];
int cnt;
queue<int>q;
void BFS(int x){
    vis[x]= true;
    q.push(x);

    while(!q.empty()){
        int curX = q.front();
        q.pop();
        for(int i=0;i<v[curX].size();i++){
            int nx = v[curX][i];

            if(!vis[nx]){
                vis[nx]=true;
                q.push(nx);
            }
        }
    }
}


int main() {
    int N,M;
    cin >>N>>M;
    for(int i=0;i<M;i++){
        int a ,b;
        cin >>a>>b;

        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            BFS(i);
            cnt++;
        }
    }
    cout << cnt <<'\n';
    return 0;
}