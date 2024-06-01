#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MX = 10;
int map[MX][MX]; // 실제 맵 정보를 저장하는 배열
int copy[MX][MX]; // 맵 정보를 복사하여 사용하는 배열
int dx[]={0,0,1,-1}; // 상하좌우 방향 이동을 위한 배열
int dy[]={1,-1,0,0};
int N,M; // 맵의 크기
int ans; // 안전 영역의 최대 크기
queue<pair<int,int>>virus; // 바이러스 위치를 저장하는 큐

// 맵 정보를 복사해 초기화 하는 함수
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            copy[i][j] = map[i][j]; // 실제 맵 정보를 복사
        }
    }
}

// BFS를 이용하여 바이러스를 퍼트리는 함수
void BFS(){
    queue<pair<int,int>>q = virus; // 바이러스 위치로 큐 초기화
    while(!q.empty()){
        int curX = q.front().first;  // 현재 위치의 x좌표
        int curY = q.front().second; // 현재 위치의 y좌표
        q.pop();                     // 큐에서 제거

        for(int i=0;i<4;i++){ // 상하좌우 4 방향 탐색
            int nx = curX+dx[i]; // 다음 위치의 x좌표
            int ny = curY+dy[i]; // 다음 위치의 y좌표

            if(nx>=0&&nx<N&&ny>=0&&ny<M&&copy[nx][ny] == 0){ // 다음 위치가 맵 내에 있고, 빈 공간일 경우
                copy[nx][ny] = 2; // 바이러스 전파
                q.push({nx,ny});  // 큐에 추가
            }
        }
    }
}

// 안전 영역의 크기를 계산하는 함수
int getArea(){
    int safe = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(copy[i][j] == 0){ // 빈 공간일 경우
                safe++;          // 안전 영역 크기 증가
            }
        }
    }
    return safe;
}

// 벽을 3개 세우는 백트래킹 함수
void back(int x){
    if(x == 3){ // 벽을 3개 세웠을 경우
        init(); // 맵 정보 복사
        BFS();  // 바이러스 전파
        ans = max(ans,getArea()); // 최대 안전 영역 크기 갱신
        return;
    }
    else{
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j] == 0){ // 빈 공간일 경우
                    map[i][j] = 1;  // 벽 세우기
                    back(x+1);      // 다음 벽 세우기
                    map[i][j] = 0;  // 벽 제거
                }
            }
        }
    }
}

int main(){
    cin >> N >> M; // 맵 크기 입력

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];       // 맵 정보 입력
            if(map[i][j] == 2){     // 바이러스 위치일 경우
                virus.push({i,j});  // 바이러스 위치 큐에 저장
            }
        }
    }

    back(0);             // 벽 세우기 시작
    cout << ans << '\n'; // 최대 안전 영역 크기 출력
    return 0;
}