#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

const int MX = 101;         // 최대 노드 수
const int INF = INT_MAX;    // 무한대를 나타내는 값
int mn = INF;               // 최소 합을 저장할 변수, 초기값은 무한대
vector<int>v[MX];           // 각 노드의 인접 노드를 저장할 벡터
int dist[MX];               // 각 노드까지의 거리를 저장할 배열
int N,M;        // 노드와 간선의 수
int ans;        // 결과를 저장할 변수

// 너비 우선 탐색 함수
int BFS(int x){
    queue<int>q;
    int sum = 0;
    dist[x] = 0; // 시작 노드의 거리는 0
    q.push(x); // 시작 노드를 큐에 삽입
    while(!q.empty()){
        int cur = q.front(); // 현재 노드
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int nx = v[cur][i]; // 인접 노드

            if(dist[nx]>=0)continue; // 이미 방문한 노드는 건너뜀
            dist[nx]= dist[cur]+1; // 인접 노드의 거리를 갱신
            sum += dist[nx]; // 거리의 합을 계산
            q.push(nx); // 인접 노드를 큐에 삽입
        }
    }
    return sum; // 거리의 합을 반환
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >>N>>M; // 노드와 간선의 수를 입력받음
    
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b; // 간선의 정보를 입력받음
        v[a].push_back(b); // 양방향 간선이므로 두 노드 모두에 간선을 추가
        v[b].push_back(a);
    }
    for(int i=1;i<=N;i++){
        fill(dist,dist+N+1,-1) ; // 거리 배열을 -1로 초기화
        int sum = BFS(i);  // 너비 우선 탐색을 수행하고 거리의 합을 계산
        if(sum>=mn)continue; // 거리의 합이 이전의 최소값보다 크거나 같으면 건너뜀
        mn = sum; // 최소값을 갱신
        ans = i; // 결과를 갱신
    }
    cout << ans ; // 결과 출력

    return  0;
}
