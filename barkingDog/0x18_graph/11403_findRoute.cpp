#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<stack>
using namespace std;

const int MX =101; // 최대 노드 수를 정의합니다.
bool arr[MX][MX]; // 인접 행렬을 정의합니다. arr[i][j]는 노드 i에서 노드 j로의 경로가 있는지 여부를 나타냅니다.
bool vis[MX]; // 방문 여부를 기록하는 배열입니다. vis[i]는 노드 i를 방문했는지 여부를 나타냅니다.
int N; // 노드의 수를 저장하는 변수입니다.

// DFS 함수입니다. x에서 y로 가는 경로가 있는지 확인합니다.
bool DFS(int x,int y){
    stack<int>s; // DFS를 위한 스택입니다.
    fill(vis,vis+N+2,0); // 방문 배열을 초기화합니다.
    s.push(x); // 시작 노드를 스택에 넣습니다.

    // 스택이 비어있지 않은 동안 반복합니다.
    while(!s.empty()){

        int cur = s.top(); // 현재 노드를 가져옵니다.
        s.pop(); // 스택에서 현재 노드를 제거합니다.

        if(vis[cur])continue; // 이미 방문한 노드라면 건너뜁니다.
        if(cur != x) vis[cur] = 1; // 시작 노드가 아니라면 방문했다고 표시합니다.

        // 모든 노드를 순회합니다.
        for(int nxt=0;nxt<N;nxt++){
            if(vis[nxt])continue; // 이미 방문한 노드라면 건너뜁니다.
            if(arr[cur][nxt]){ // 현재 노드에서 다음 노드로 가는 경로가 있다면
                if(nxt == y) return true; // 다음 노드가 목표 노드라면 true를 반환합니다.
                s.push(nxt); // 다음 노드를 스택에 넣습니다.
            }
        }
    }
    return false; // 경로를 찾지 못했다면 false를 반환합니다.
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N; // 노드의 수를 입력받습니다.
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j]; // 인접 행렬을 입력받습니다.
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << DFS(i,j) << " "; // 각 노드에서 다른 모든 노드로의 경로 존재 여부를 출력합니다.
        }
        cout << '\n';
    }
    return 0;
}