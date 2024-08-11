#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MX = 11;
const int INF = 987987987;
int N,S,ans = INF;;
int map[MX][MX];
bool vis[MX];
void func(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(map[i][j] > map[i][k] +map[k][j] ){
                    map[i][j] = map[i][k] +map[k][j];
                }
            }
        }
    }
}
// 백트래킹을 사용하여 거리합의 최소 값을 찾음 
void back(int cur,int sum,int x){
    // 모든 노드를 방문한 경우
    if(x==N){
        // 최소 비용 갱신
        if(ans>sum) ans = sum;
        return;
    }

    for(int i=0;i<N;i++){
        // 아직 방문 하지 않았으면
        if(!vis[i]){
            // 방문하고
            vis[i]=true;
            // 다음 노드를 방문하고 거리 해당 노드의 거리 값을 합에 누적시킴
            back(i,sum+map[cur][i],x+1);
            // 백트래킹을 위해 방문 해제
            vis[i]=false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N >> S;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }

    func();
    vis[S] = true;
    back(S,0,1);
    cout << ans << '\n';
    return 0;
}