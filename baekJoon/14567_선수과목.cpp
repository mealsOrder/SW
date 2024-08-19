#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MX = 10001;

int N,M;            // 노드수, 간선의 수
int in[MX];         // 진입 차수를 저장하는 배열
int ans[MX];        // 학기수 저장하는 배열
vector<int>adj[MX]; // 인접 리스트
queue<int>q;        // 위상 정렬을 위한 큐

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    
    // 간선 정보 입력
    while(M--){
        int a,b;
        cin >> a>>b;
        adj[a].push_back(b); // a에서 b로 가는 간선 입력
        in[b]++; // b의 진입 차수 값 증가
    }

    // indegree 값이 0인 정점들을 모두 큐에 추가
    for(int i=1;i<=N;i++){
        if(in[i] == 0)q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        //현재 노드와 연결된 모든 노드들을 탐색
        for(int i=0;i<adj[cur].size();i++){
            int nx = adj[cur][i];
            in[nx]--;  // 연결된 노드의 진입 차수를 감소
            // 진입 차수가 0이 된 노드를 큐에 삽입
            if(in[nx] == 0){
                q.push(nx);
                // 현재 노드를 거쳐서 갈 때 더 많은 학기가 필요하다면 업데이트
                if(ans[nx] < ans[cur]+1) ans[nx] = ans[cur]+1;
            }
        }
    }
    // 필요한 학기 수를 출력
    for(int i=1;i<=N;i++){
        cout << ans[i]+1 << " "; // 0학기 부터 시작하므로 모든 값에 +1
    }
    return 0;
}