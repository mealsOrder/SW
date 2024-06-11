#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
const int MX = 101;
bool arr[MX][MX];
bool vis[MX];
int N;
// x -> y 갈수있으면 1 아니면 0 반환하는 함수
int DFS(int x,int y){
    stack<int>s;
    fill(vis,vis+N+2,0); // 방문 정보 초기화
    s.push(x);
    while(!s.empty()){
        int cur = s.top();
        s.pop();

        // 이미 방문했다면 pass
        if(vis[cur])continue;
        // 현재 좌표가 출발 좌표와 다르다면 방문 표시
        if(cur != x) vis[cur] = true;

        for(int nx=0;nx<N;nx++){
            // 이미 방문 했다면 pass
            if(vis[nx])continue;
            
            if(arr[cur][nx]){
                if(nx == y)return true;
                s.push(nx);
            }
        }
    }
    // 위조건을 빠져 나온거면 도달하지 못함을 의미
    return false;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << DFS(i,j) << " ";
        }
        cout << '\n';
    }

	return 0;
}