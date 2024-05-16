#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>

using namespace std;


/*
이 코드는 주어진 지도에서 시작점부터 도착점까지의 최단 경로를 찾는 문제를 BFS 알고리즘을 이용하여 해결한 것입니다.


BFS 함수 구현
시작점의 거리를 0으로 초기화하고 큐에 삽입
큐가 빌 때까지 반복하며, 상하좌우 방향 탐색
새로운 점이 지도 범위 내에 있고, 
현재까지의 최단 거리보다 작은 경우 거리 갱신 및 큐에 삽입
도착점의 최단 거리 반환


테스트 케이스 개수 입력받기
각 테스트 케이스에 대해 지도 정보 입력받고, 거리 배열 초기화
BFS 함수 실행하여 최단 경로 계산

*/


const int MAX = 101;
const int INF = INT_MAX;
int map[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N;

queue<pair<int,int>>q;

// BFS 알고리즘을 이용하여 최단 경로 찾기
int BFS(){
    // 시작점의 거리를 0으로 초기화하고 큐에 삽입
    dist[0][0] = 0;
    q.push({0,0});

    // 큐가 빌 때까지 반복
    while(!q.empty()){
        // 현재 점을 꺼내기
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        // 상하좌우 4방향 탐색
        for(int i=0;i<4;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            // 지도 범위 내에 있는 경우
            if(nx>=0 && nx<N && ny>=0 && ny<N){
                // 다음 누적 거리 > 현재 누적거리 + 다음시간 이면
				// 다음 누적 거리를 최소값으로 갱신해주고 q에 푸시
                if(dist[nx][ny] > dist[curX][curY] + map[nx][ny]){
                    dist[nx][ny] = dist[curX][curY] + map[nx][ny];
                    q.push({nx,ny});
                }
            }
        }
    }

    // 도착점의 최단 거리 반환
    return dist[N-1][N-1];
}

int main(){
    int T;
    cin >> T;

    // 테스트 케이스 개수만큼 반복
    for(int t=1;t<=T;t++){
        cin >> N;

        // 지도 정보 입력받기
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%1d",&map[i][j]);
                dist[i][j] = INF; // 모든 점의 거리를 무한대로 초기화
            }
        }

        // BFS 알고리즘 실행
        int ans = BFS();

        // 결과 출력
        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}