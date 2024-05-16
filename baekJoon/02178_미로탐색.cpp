#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;



/*
최단거리 조건을 넣지 않았는데 최단거리로 결과가 나오는 이유는?

이 코드에서 최단거리로 결과가 나오는 이유는 BFS 알고리즘의 특성 때문입니다.

BFS는 너비 우선 탐색 방식으로, 현재 노드와 인접한 노드들을 먼저 방문하고 
그 다음 층의 노드들을 방문하는 방식입니다. 이 특성 때문에 목적지에 도달하는 
가장 빠른 경로를 자동으로 찾게 됩니다.

(x,y) 시작 인자를 주고 해도 상관 없음!!
시작점(1, 1)을 큐에 넣고, dist[1][1]을 1로 초기화합니다.
큐에서 노드를 꺼내면서 상하좌우 인접 노드를 탐색합니다.
인접 노드가 도달 가능하고 아직 방문하지 않은 경우, 
해당 노드의 dist 값을 현재 노드의 dist 값 + 1로 업데이트하고 큐에 넣습니다.
이 과정을 반복하면서 도착점(N, M)에 도달하게 됩니다.
도착점에 도달했을 때의 dist[N][M] 값이 최단거리가 됩니다.
이처럼 BFS 알고리즘의 특성 상 목적지에 도달하는 가장 빠른 경로를 자동으로 찾게 됩니다. 
따라서 별도의 최단거리 조건을 명시하지 않아도 결과가 최단거리가 됩니다.


*/

const int MAX = 101; // 최대 입력 크기 정의
int map[MAX][MAX]; // 입력 맵을 저장하는 2D 배열
int dist[MAX][MAX]; // 각 셀까지의 최단 거리를 저장하는 2D 배열
bool visited[MAX][MAX]; // 각 셀의 방문 여부를 저장하는 2D 배열
int dx[4]={0,0,1,-1}; // 상하좌우 이동을 위한 x 좌표 변화량
int dy[4]={1,-1,0,0}; // 상하좌우 이동을 위한 y 좌표 변화량

queue<pair<int,int>> q; // BFS를 위한 큐
int N, M; // 입력 맵의 크기

// BFS 함수
int BFS(){
    // 시작점 (1, 1)을 큐에 삽입하고, 거리를 1로 초기화, 방문 표시
	// 인자를 x y 로 받아서 해도 상관 없음!
    q.push({1,1});
    dist[1][1]=1;
    visited[1][1] = true;
    
    // 큐가 빌 때까지 반복
    while(!q.empty()){
        // 큐의 front 노드 꺼내기
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 도착점에 도달했다면 거리 반환
        if(x==N && y==M) return dist[N][M];
        
        // 상하좌우 이동 시도
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            // 이동한 좌표가 맵 범위 내이고, 이동할 수 있는 경로이며, 아직 방문하지 않은 경우
            if(nx>0 && nx<=N && ny>0 &&ny<=M && map[nx][ny]==1 &&!visited[nx][ny] ){
                // 거리를 현재 거리 + 1로 업데이트하고, 큐에 추가, 방문 표시
                dist[nx][ny] = dist[x][y]+1;
                q.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }
    
    // 도착점에 도달하지 못한 경우 -1 반환
    return -1;
}

int main(){
    // 입력 받기
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%1d",&map[i][j]);
        }
    }
    
    // BFS 실행 후 결과 출력
    int ans = BFS();
    cout << ans << endl;
    
    return 0;
}