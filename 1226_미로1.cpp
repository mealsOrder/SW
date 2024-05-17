#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;


/*

이 문제의 핵심은 
큐를 초기화하는 것 
미로 지도에서 시작 지점(2)과 도착 지점(3)의 좌표를 받아 0으로 변경해주는 것

미로 지도와 방문 여부 배열, 시작/도착 지점 좌표 등을 케이스마다 초기화합니다.
매 테스트 케이스마다 큐를 초기화하여 이전 테스트 케이스의 영향을 받지 않도록 합니다.
시작 지점(2)과 도착 지점(3)의 좌표를 따로 저장하고 해당 위치를 0으로 변경합니다.
BFS 알고리즘을 이용하여 시작 지점에서 도착 지점까지의 경로를 탐색합니다.
도착 지점에 도달하면 1을 반환하고, 도달하지 못하면 0을 반환합니다.

*/


const int MAX = 17; // 지도의 최대 크기 상수 정의

int map[MAX][MAX]; // 미로 지도를 저장할 2차원 배열

int dx[4] = {0,0,1,-1}; // 상하좌우 방향 델타 값
int dy[4] = {1,-1,0,0};
int si,sj; // 시작 좌표
int ei,ej; // 도착 좌표
bool visited[MAX][MAX]; // 방문 여부 체크 배열
queue<pair<int,int>> q; // BFS 탐색을 위한 큐

// BFS 알고리즘을 이용하여 시작 지점에서 도착 지점까지의 경로 탐색
int BFS(int x,int y){
    visited[x][y] = true; // 시작 지점 방문 처리
    q.push({x,y}); // 시작 지점을 큐에 삽입

    while(!q.empty()){ // 큐가 빌 때까지 반복
        int curX = q.front().first; // 현재 노드의 x좌표
        int curY = q.front().second; // 현재 노드의 y좌표
        if(curX == ei && curY == ej) return 1; // 도착 지점에 도달하면 1 반환
        q.pop(); // 현재 노드 큐에서 제거

        for(int i=0;i<4;i++){ // 상하좌우 방향 탐색
            int nx = curX+dx[i]; // 다음 x좌표
            int ny = curY+dy[i]; // 다음 y좌표

            // 다음 좌표가 지도 범위 내이고, 벽이 아니며, 아직 방문하지 않은 경우
            if(nx>=0&&nx<16&&ny>=0&&ny<16&& map[nx][ny]==0 && !visited[nx][ny]){
                visited[nx][ny] = true; // 다음 좌표 방문 처리
                q.push({nx,ny}); // 다음 좌표를 큐에 삽입
            }
        }
    }

    return 0; // 도착 지점에 도달하지 못한 경우 0 반환
}

int main(){
    for(int t=1;t<=10;t++){ // 총 10개의 테스트 케이스
        int num;
        cin >> num;
        memset(map,0,sizeof(map)); // 미로 지도 초기화
        memset(visited,false,sizeof(visited)); // 방문 여부 배열 초기화
        while(!q.empty()) q.pop(); // 큐 초기화

        // 미로 지도 입력 받기
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                scanf("%1d",&map[i][j]);
                // 시작 지점(2)과 도착 지점(3)의 좌표 저장 및 해당 위치를 0으로 변경
                if(map[i][j] == 2){
                    map[i][j] = 0;
                    si=i;
                    sj=j;
                }
                else if(map[i][j]==3){
                    map[i][j] = 0;
                    ei=i;
                    ej=j;
                }
            }
        }

        // BFS 알고리즘을 이용해 출발 지점에서 도착 지점까지의 경로 탐색
        cout << "#" << t << " " << BFS(si,sj) << endl;
    }

    return 0;
}